class Solution {
public:
    int rob(vector<int>& nums) {
        int mx = -1, ans = 0;
        vector<int>v;
        v.push_back(nums[0]);
        mx = max(mx,nums[0]);
        ans = mx;

        for(int i=1;i<nums.size();i++){
            if(i==1){
                v.push_back(max(mx,nums[i]));
            } else{
                mx = max(mx,v[i-2]);
                v.push_back(mx+nums[i]);
            }
            ans = max(ans, v[v.size()-1]);
        }

        return ans;
    }
};