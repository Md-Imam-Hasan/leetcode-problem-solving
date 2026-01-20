class Solution {
  public:
      vector<int> minBitwiseArray(vector<int>& nums) {
          vector<int> ans;
  
          for(int i = 0;i<nums.size();i++){
              bool good = false;
              for(int j = 0;j<nums[i];j++){
                  if((j|(j+1)) == nums[i]){
                      good = true;
                      ans.push_back(j);
                      break;
                  }
              }
              if(!good){
                  ans.push_back(-1);
              }
          }
  
          return ans;
      }
  };