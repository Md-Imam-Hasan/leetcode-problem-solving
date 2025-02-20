#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
      int binaryToDecimal(const std::string& binaryStr) {
          int decimal = 0;
          int length = binaryStr.length();
  
          for (int i = 0; i < length; ++i) {
              if (binaryStr[length - 1 - i] == '1') {
                  decimal += pow(2, i);
              }
          }
  
          return decimal;
      }
      std::string intToBinary(int num, int desiredLength) {
          std::string binary = "";
          while (num > 0) {
              binary += (num % 2) ? '1' : '0';
              num >>= 1;
          }
  
          // Reverse the string to represent the correct binary form
          std::reverse(binary.begin(), binary.end());
  
          // Check if padding is needed
          int currentLength = binary.length();
          if (currentLength < desiredLength) {
              // Pad with leading zeros
              binary = std::string(desiredLength - currentLength, '0') + binary;
          }
  
          return binary;
      }
      string findDifferentBinaryString(vector<string>& nums) {
          int n = nums.size(), i, j, m = nums[0].size();
          vector<int> dec_num;
  
          for (i = 0; i < n; i++) {
              int x = binaryToDecimal(nums[i]);
              dec_num.push_back(x);
          }
  
          sort(dec_num.begin(), dec_num.end());
  
          for (i = 0, j = 0; i < round(pow(2, n)) and j < dec_num.size();
               i++, j++) {
              if (dec_num[j] != i) {
                  return intToBinary(i, m);
              }
          }
          return intToBinary(i, m);
      }
  };