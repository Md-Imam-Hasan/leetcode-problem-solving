class Solution {
  public:
      vector<int> a, b;
      vector<vector<int>> memo;
      int N, M;
      const int neg = -1e9;
      int run(int i, int j) {
          if (i == N || j == M) {
              return neg;
          }
  
          if (memo[i][j] != INT_MIN)
              return memo[i][j];
  
          int res = max({run(i + 1, j), run(i, j + 1), a[i] * b[j],
                         run(i + 1, j + 1) + a[i] * b[j]});
  
          return memo[i][j] = res;
      }
      int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
          a = nums1;
          b = nums2;
          N = a.size(), M = b.size();
  
          memo.assign(N, vector<int>(M, INT_MIN));
          return run(0, 0);
      }
  };


// Approach 2: With explicit 'started' flag and 3D memoization
class Solution2 {
public:
    vector<int> nums1, nums2;
    vector<vector<vector<int>>> memo;  // memo[i][j][started]
    int N, M;
    const int NEG_INF = -(1 << 30);
    
    int run(int i, int j, int started) {
        // Base case: reached end of either array
        if (i == N || j == M) {
            if (started) return 0;      // Valid: we picked at least one pair
            return NEG_INF;             // Invalid: must pick at least one pair
        }
        
        // Check memo
        if (memo[i][j][started] != INT_MIN) {
            return memo[i][j][started];
        }
        
        int best = INT_MIN;
        
        // Option 1: Skip nums1[i]
        best = max(best, run(i + 1, j, started));
        
        // Option 2: Skip nums2[j]
        best = max(best, run(i, j + 1, started));
        
        // Option 3: Take both nums1[i] and nums2[j]
        best = max(best, run(i + 1, j + 1, 1) + nums1[i] * nums2[j]);
        
        return memo[i][j][started] = best;
    }
    
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        nums1 = a;
        nums2 = b;
        N = nums1.size();
        M = nums2.size();
        
        // 3D memo: [N][M][2] for (i, j, started)
        memo.assign(N, vector<vector<int>>(M, vector<int>(2, INT_MIN)));
        
        return run(0, 0, 0);  // started = 0 (false)
    }
};