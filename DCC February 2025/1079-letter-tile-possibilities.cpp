#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
      int wayBuilder(vector<int>& freq) {
          int ways = 0;
          for (int i = 0; i < 26; i++) {
              if (freq[i] > 0) {
                  freq[i]--;
                  ways += 1 + wayBuilder(freq);
                  freq[i]++;
              }
          }
  
          return ways;
      }
      int numTilePossibilities(string tiles) {
          vector<int> freq(26, 0);
          for (auto c : tiles)
              freq[c - 'A']++;
  
          return wayBuilder(freq);
      }
  };