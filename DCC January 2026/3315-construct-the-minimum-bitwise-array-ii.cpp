class Solution {
  public:
      vector<int> minBitwiseArray(vector<int>& nums) {
          vector<int> ans;
  
          for (long long R : nums) {
              // Only even prime → impossible
              if (R == 2) {
                  ans.push_back(-1);
                  continue;
              }
  
              // Count trailing ones in R
              int k = __builtin_ctzll(~R);
  
              // Smallest possible a
              int a = R - (1 << (k - 1));
              ans.push_back(a);
          }
  
          return ans;
      }
  };