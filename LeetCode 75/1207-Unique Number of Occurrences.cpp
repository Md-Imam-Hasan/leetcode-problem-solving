class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_map<int, bool> check;
        for (int x : arr) {
            mp[x]++;
        }

        for (auto& x : mp) {
            if (check[x.second]) {
                return false;
            } else {
                check[x.second] = true;
            }
        }
        return true;
    }
};