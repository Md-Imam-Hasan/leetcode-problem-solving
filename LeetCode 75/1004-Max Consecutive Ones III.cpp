class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, count = 0;
        int i = 0, j = 0, l = nums.size();

        while (j < l) {
            if (count > k) {
                if (nums[i] == 0)
                    count--;
                i++;
                continue;
            }
            if (nums[j] == 0) {
                count++;
            }
            if (count <= k) {
                ans = max(ans, j - i + 1);
            }
            j++;
        }

        return ans;
    }
};