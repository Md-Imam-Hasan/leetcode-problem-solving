class Solution {
  public:
      int maximalRectangle(vector<vector<char>>& matrix) {
          int n = matrix.size();
          int m = matrix[0].size();
          vector<int> heights(m, 0);
          int maxArea = 0;
  
          for (int k = 0; k < n; k++) {
              for (int j = 0; j < m; j++) {
                  if (matrix[k][j] == '1') {
                      heights[j] += 1;
                  } else {
                      heights[j] = 0;
                  }
              }
              stack<pair<int, int>> st;
  
              for (int i = 0; i < m; i++) {
                  int start = i;
  
                  while (!st.empty() && st.top().second > heights[i]) {
                      auto top = st.top();
                      maxArea = max(maxArea, top.second * (i - top.first));
                      start = top.first;
                      st.pop();
                  }
                  st.push({start, heights[i]});
              }
  
              while (!st.empty()) {
                  auto top = st.top();
                  maxArea = max(maxArea, top.second * (m - top.first));
                  st.pop();
              }
          }
  
          return maxArea;
      }
  };