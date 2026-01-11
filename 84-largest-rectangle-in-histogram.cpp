class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            stack<pair<int, int>> st;
            int maxArea = 0;
            int n = heights.size();
    
            for (int i = 0; i < n; i++) {
                int start = i;
    
                while (!st.empty() && st.top().second > heights[i]) {
                    auto top = st.top();
                    maxArea = max(maxArea, top.second * (i - top.first));
                    start = top.first;
                    st.pop();
                }
                st.push({start, heights[i]});
            }
    
            while (!st.empty()) {
                auto top = st.top();
                maxArea = max(maxArea, top.second * (n - top.first));
                st.pop();
            }
    
            return maxArea;
        }
    };