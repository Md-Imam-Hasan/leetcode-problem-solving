#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    int minimizeXor(int num1, int num2) {
        int i = 0, numberOfSetBits = countSetBits(num2);
        vector<bool> bitPos(32, false);
        while (num1) {
            if (num1 & 1) {
                bitPos[i] = true;
            }
            num1 >>= 1;
            i++;
        }

        int ans = 0;

        for (i = 31; i >= 0; i--) {
            if (numberOfSetBits && bitPos[i]) {
                ans |= 1 << i;
                numberOfSetBits--;
            }
        }

        i = 0;

        while (numberOfSetBits && i < 32) {
            if (!bitPos[i]) {
                ans |= 1 << i;
                numberOfSetBits--;
            }
            i++;
        }

        return ans;
    }
};