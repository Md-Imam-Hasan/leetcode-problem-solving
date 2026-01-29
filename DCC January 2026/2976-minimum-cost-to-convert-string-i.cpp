class Solution {
  public:
      long long minimumCost(string source, string target, vector<char>& original,
                            vector<char>& changed, vector<int>& cost) {
          int A = 26;
          long long INF = 1e11; 
          vector<vector<long long>> dist(A, vector<long long>(A, INF));
  
          for (int i = 0; i < A; i++) {
              dist[i][i] = 0;
          }
  
          for (int i = 0; i < original.size(); i++) {
              int x = original[i] - 'a';
              int y = changed[i] - 'a';
              int c = cost[i];
  
              dist[x][y] = min(dist[x][y], (long long)c);
          }
  
          for (int k = 0; k < A; k++) {
              for (int i = 0; i < A; i++) {
                  for (int j = 0; j < A; j++) {
                      dist[i][j] = min(dist[i][j], dist[k][j] + dist[i][k]);
                  }
              }
          }
  
          long long total = 0;
  
          for (int i = 0; i < source.length(); i++) {
              int x = source[i] - 'a';
              int y = target[i] - 'a';
  
              total += dist[x][y];
          }
  
          return total >= INF ? -1 : total;
      }
  };