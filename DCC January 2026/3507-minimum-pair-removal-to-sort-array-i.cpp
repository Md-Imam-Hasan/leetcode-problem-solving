class Solution {
  public:
      int minimumPairRemoval(vector<int>& nums) {
          int operations = 0;
  
          while (true) {
              bool isSorted = true;
              for (int i = 1; i < nums.size(); i++) {
                  if (nums[i] < nums[i - 1]) {
                      isSorted = false;
                      break;
                  }
              }
              if (isSorted)
                  break;
  
              int minSum = INT_MAX;
              int minIndex = -1;
  
              for (int i = 0; i < nums.size() - 1; i++) {
                  int sum = nums[i] + nums[i + 1];
                  if (sum < minSum) {
                      minSum = sum;
                      minIndex = i;
                  }
              }
  
              nums[minIndex] = minSum;
              nums.erase(nums.begin() + minIndex + 1);
              operations++;
          }
  
          return operations;
      }
  };