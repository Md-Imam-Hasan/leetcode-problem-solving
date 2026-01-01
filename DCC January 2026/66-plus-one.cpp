class Solution {
  public:
      vector<int> plusOne(vector<int>& digits) {
          int carry = 0, temp;
          bool yes = 0;
          for (int i = digits.size() - 1; i >= 0; i--) {
              if (!yes) {
                  temp = digits[i] + 1;
                  digits[i] = temp % 10;
                  carry = temp / 10;
                  yes = 1;
              } else if (carry) {
                  temp = digits[i] + carry;
                  digits[i] = temp % 10;
                  carry = temp / 10;
              } else
                  break;
          }
          if(carry){
              digits.insert(digits.begin(), carry);
          }
          return digits;
      }
};