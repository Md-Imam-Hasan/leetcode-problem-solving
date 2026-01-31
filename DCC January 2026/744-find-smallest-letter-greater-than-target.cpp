class Solution {
  public:
      char nextGreatestLetter(vector<char>& letters, char target) {
          int tr = target - 'a';
          char ans;
          bool good = false;
  
          for (int i = 0; i < letters.size(); i++) {
              int xc = letters[i] - 'a';
              if (xc > tr) {
                  good = true;
                  ans = letters[i];
                  break;
              }
          }
  
          return good ? ans : letters[0];
      }
  };