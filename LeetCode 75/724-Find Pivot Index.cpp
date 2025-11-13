class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        vector<int> ltr, rtl;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            ltr.push_back(sum);
            sum += nums[i];
        }
        sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            rtl.push_back(sum);
            sum += nums[i];
        }

        reverse(rtl.begin(), rtl.end());

        for (int i = 0; i < ltr.size(); i++) {
            if (ltr[i] == rtl[i]) {
                return i;
            }
        }
        return -1;
    }
};