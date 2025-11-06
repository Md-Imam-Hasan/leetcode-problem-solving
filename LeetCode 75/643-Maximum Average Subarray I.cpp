class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double mx = INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(i>=k){
                sum-=nums[i-k];
            }
            if(i>=k-1){
                mx = max(mx,sum);
            }
        }
        return round((mx/k) * 1e5) / 1e5;
    }
};