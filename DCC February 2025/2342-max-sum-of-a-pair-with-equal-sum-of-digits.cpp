#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
      int maximumSum(vector<int>& nums) {
          int n = nums.size(), i, j, ans = -1;
          unordered_map<int, int> digits_value;
  
          for (i = 0; i < n; i++) {
              int sum_digits = 0;
              int value = nums[i];
              while (value) {
                  sum_digits += value % 10;
                  value /= 10;
              }
              if (digits_value[sum_digits]) {
                  ans = max(ans, nums[i] + digits_value[sum_digits]);
              }
              digits_value[sum_digits] = max(digits_value[sum_digits], nums[i]);
          }
  
          return ans;
      }
  };