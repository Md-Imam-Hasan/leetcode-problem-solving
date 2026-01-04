class Solution {
  public:
      int sumFourDivisors(vector<int>& nums) {
          long long sum = 0;
          for (int i = 0; i < nums.size(); i++) {
              vector<int> divisors;
              for (int j = 1; j * j <= nums[i]; j++) {
                  if (nums[i] % j == 0) {
                      divisors.push_back(j);
                      if (j != nums[i] / j) {
                          divisors.push_back(nums[i] / j);
                      }
                  }
              }
              if (divisors.size() == 4) {
                  sum += accumulate(divisors.begin(), divisors.end(), 0LL);
              }
          }
          return sum;
      }
  };