class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minc;
        minc.push_back(cost[0]);
        minc.push_back(cost[1]);

        for (int i = 2; i < cost.size(); i++) {
            int temp = min(minc[i - 1], minc[i - 2]);
            minc.push_back(cost[i] + temp);
        }

        int l = cost.size();

        return min(minc[l - 1], minc[l - 2]);
    }
};