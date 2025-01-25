#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size(), i;
        if (len == 1 && flowerbed[0] == 0) {
            return true;
        }

        for (i = 0; i < len; i++) {
            if (n == 0)
                break;
            if (i == 0 && flowerbed[i] != 1 && flowerbed[i + 1] != 1) {
                flowerbed[i] = 1;
                n--;
            } else if (i == len - 1 && flowerbed[i] != 1 &&
                       flowerbed[i - 1] != 1) {
                flowerbed[i] = 1;
                n--;
            } else if (i > 0 && i < len - 1 && flowerbed[i] != 1 &&
                       flowerbed[i - 1] != 1 && flowerbed[i + 1] != 1) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n == 0;
    }
};