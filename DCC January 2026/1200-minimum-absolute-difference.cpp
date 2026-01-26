class Solution {
  public:
      int binarySearch(vector<int>& arr, int x) {
          int low = 0;
          int high = arr.size() - 1;
          while (low <= high) {
              int mid = low + (high - low) / 2;
  
              // Check if x is present at mid
              if (arr[mid] == x)
                  return mid;
  
              // If x greater, ignore left half
              if (arr[mid] < x)
                  low = mid + 1;
  
              // If x is smaller, ignore right half
              else
                  high = mid - 1;
          }
  
          // If we reach here, then element was not present
          return -1;
      }
      vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
          int n = nums.size();
  
          sort(nums.begin(), nums.end());
  
          int minDiff = INT_MAX;
  
          for (int i = 1; i < n; i++) {
              minDiff = min(minDiff, abs(nums[i] - nums[i - 1]));
          }
  
          vector<vector<int>> ans;
  
          for (int i = 0; i < n; i++) {
              int x = nums[i];
              int y = binarySearch(nums, x + minDiff);
  
              if (y > i) {
                  ans.push_back({ x, nums[y] });
              }
          }
  
          return ans;
      }
  };