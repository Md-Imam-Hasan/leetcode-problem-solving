class Solution {
  public:
      long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
          unordered_set<string> allStrings;
          unordered_set<int> validLengths = {1}; // Always consider single characters
          
          // Add original and changed strings
          for (const string& s : original) {
              allStrings.insert(s);
              validLengths.insert(s.length());
          }
          for (const string& s : changed) {
              allStrings.insert(s);
          }
          
          // Map strings to indices
          unordered_map<string, int> strToIdx;
          vector<string> idxToStr;
          
          for (const string& s : allStrings) {
              strToIdx[s] = idxToStr.size();
              idxToStr.push_back(s);
          }
          
          // Add single characters that differ between source and target
          for (int i = 0; i < source.length(); i++) {
              if (source[i] != target[i]) {
                  string s(1, source[i]);
                  if (strToIdx.find(s) == strToIdx.end()) {
                      strToIdx[s] = idxToStr.size();
                      idxToStr.push_back(s);
                  }
                  
                  string t(1, target[i]);
                  if (strToIdx.find(t) == strToIdx.end()) {
                      strToIdx[t] = idxToStr.size();
                      idxToStr.push_back(t);
                  }
              }
          }
          
          int n = idxToStr.size();
          vector<vector<long long>> dist(n, vector<long long>(n, LLONG_MAX));
          
          // Initialize
          for (int i = 0; i < n; i++) {
              dist[i][i] = 0;
          }
          
          // Add edges
          for (int i = 0; i < original.size(); i++) {
              int u = strToIdx[original[i]];
              int v = strToIdx[changed[i]];
              dist[u][v] = min(dist[u][v], (long long)cost[i]);
          }
          
          // Floyd-Warshall
          for (int k = 0; k < n; k++) {
              for (int i = 0; i < n; i++) {
                  for (int j = 0; j < n; j++) {
                      if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                      }
                  }
              }
          }
          
          int len = source.length();
          vector<long long> dp(len + 1, LLONG_MAX);
          dp[0] = 0;
          
          for (int i = 0; i < len; i++) {
              if (dp[i] == LLONG_MAX) continue;
              
              // Try all valid lengths
              for (int l : validLengths) {
                  if (i + l > len) continue;
                  
                  string src_sub = source.substr(i, l);
                  string tgt_sub = target.substr(i, l);
                  
                  if (src_sub == tgt_sub) {
                      // No transformation needed
                      dp[i + l] = min(dp[i + l], dp[i]);
                  } else {
                      // Try transformation
                      if (strToIdx.count(src_sub) && strToIdx.count(tgt_sub)) {
                          int src_idx = strToIdx[src_sub];
                          int tgt_idx = strToIdx[tgt_sub];
                          
                          if (dist[src_idx][tgt_idx] != LLONG_MAX) {
                              dp[i + l] = min(dp[i + l], dp[i] + dist[src_idx][tgt_idx]);
                          }
                      }
                  }
              }
          }
          
          return dp[len] == LLONG_MAX ? -1 : dp[len];
      }
  };