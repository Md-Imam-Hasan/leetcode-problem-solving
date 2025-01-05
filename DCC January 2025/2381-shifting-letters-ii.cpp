#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int i, start, end, direction, j, sum = 0, len = s.length();
        vector<int>arr(len);
        for(i=0;i<shifts.size();i++){
            start = shifts[i][0];
            end = shifts[i][1];
            direction = shifts[i][2];
            arr[start] += direction == 0 ? -1 : 1;
            if (end + 1 < len) {
                arr[end + 1] -= direction == 0 ? -1 : 1;
            }
        }

        for (int i = 0; i < len; i++) {
            sum += arr[i];
            int newIndex = (s[i] - 'a' + sum) % 26;
            while (newIndex < 0) {
                newIndex += 26;
            }
            s[i] = 'a' + newIndex;
        }

        return s;
    }
};