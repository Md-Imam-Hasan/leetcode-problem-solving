class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<vector<int>> ans(2);

        for (int x : nums1) {
            mp[x] = 1;
        }

        for (int x : nums2) {
            if (mp[x] == 1 || mp[x] == -1) {
                mp[x] = -1;
            } else {
                mp[x] = 2;
            }
        }

        for (auto& x : mp) {
            if (mp[x.first] == 1) {
                ans[0].push_back(x.first);
            } else if (mp[x.first] == 2) {
                ans[1].push_back(x.first);
            }
        }

        return ans;
    }
};