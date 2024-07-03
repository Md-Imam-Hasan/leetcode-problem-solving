class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, ans = 0;
        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[right] > nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left];
    }
};