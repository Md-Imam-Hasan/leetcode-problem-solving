class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0, l = nums.size(), count = 0, ans = 0;

        while (j < l) {
            if (count > 1) {
                if (nums[i] == 0)
                    count--;
                i++;
                continue;
            }
            if (nums[j] == 0) {
                count++;
            }
            if (count <= 1) {
                ans = max(ans, j - i);
            }
            j++;
        }

        return ans;
    }
};