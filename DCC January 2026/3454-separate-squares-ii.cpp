class Solution {
public:
    int n;
    vector<long long> xs;
    vector<int> cnt;    // count of active rectangles covering each segment
    vector<double> len; // covered length in each segment tree node
    
    void update(int node, int lo, int hi, int l, int r, int val) {
        if (r < lo || hi < l) return;
        if (l <= lo && hi <= r) {
            cnt[node] += val;
        } else {
            int mid = (lo + hi) / 2;
            update(2*node, lo, mid, l, r, val);
            update(2*node+1, mid+1, hi, l, r, val);
        }
        
        if (cnt[node] > 0) {
            len[node] = xs[hi + 1] - xs[lo];
        } else if (lo == hi) {
            len[node] = 0;
        } else {
            len[node] = len[2*node] + len[2*node+1];
        }
    }
    
    double separateSquares(vector<vector<int>>& squares) {
        // Coordinate compression for x
        for (auto& sq : squares) {
            xs.push_back(sq[0]);
            xs.push_back((long long)sq[0] + sq[2]);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        
        n = xs.size() - 1; // number of x-segments
        cnt.assign(4 * n, 0);
        len.assign(4 * n, 0);
        
        auto getIdx = [&](long long x) {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };
        
        // Events: {y, type, x1_idx, x2_idx}
        // type: 0 = bottom (add), 1 = top (remove) - sort bottom before top at same y
        vector<tuple<long long, int, int, int>> events;
        
        for (auto& sq : squares) {
            long long x1 = sq[0], y1 = sq[1], side = sq[2];
            int idx1 = getIdx(x1), idx2 = getIdx(x1 + side);
            events.push_back({y1, 0, idx1, idx2});
            events.push_back({y1 + side, 1, idx1, idx2});
        }
        
        sort(events.begin(), events.end());
        
        // Build segments: {y1, y2, width}
        vector<tuple<double, double, double>> segments;
        double lastY = get<0>(events[0]);
        int i = 0;
        
        while (i < events.size()) {
            double curY = get<0>(events[i]);
            
            if (curY > lastY && len[1] > 0) {
                segments.push_back({lastY, curY, len[1]});
            }
            
            // Process all events at curY
            while (i < events.size() && get<0>(events[i]) == curY) {
                auto [y, type, idx1, idx2] = events[i];
                int delta = (type == 0) ? 1 : -1;
                if (idx1 < idx2) {
                    update(1, 0, n - 1, idx1, idx2 - 1, delta);
                }
                i++;
            }
            
            lastY = curY;
        }
        
        // Total area and find split point
        double totalArea = 0;
        for (auto& [y1, y2, w] : segments) {
            totalArea += w * (y2 - y1);
        }
        
        double target = totalArea / 2.0;
        double areaBelow = 0;
        
        for (auto& [y1, y2, w] : segments) {
            double segArea = w * (y2 - y1);
            if (areaBelow + segArea >= target) {
                return y1 + (target - areaBelow) / w;
            }
            areaBelow += segArea;
        }
        
        return get<1>(segments.back());
    }
};
