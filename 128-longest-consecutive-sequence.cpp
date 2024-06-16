#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, bool> mp;

        for (auto &it : nums)
        {
            mp[it] = true;
        }

        int lq = 0, cnt = 0, pe;

        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            if (i == mp.begin())
            {
                cnt++;
            }
            else if (i->first == pe + 1)
            {
                cnt++;
            }
            else
            {
                cnt = 1;
            }
            pe = i->first;
            lq = max(lq, cnt);
        }

        return lq;
    }
};

// class Solution {
// public:
//     int longestConsecutive(vector<int> &nums) {
//         if (nums.empty()) return 0;

//         unordered_set<int> numSet(nums.begin(), nums.end());
//         int longestStreak = 0;

//         for (const int &num : numSet) {
//             // Check if it's the start of a sequence
//             if (numSet.find(num - 1) == numSet.end()) {
//                 int currentNum = num;
//                 int currentStreak = 1;

//                 while (numSet.find(currentNum + 1) != numSet.end()) {
//                     currentNum++;
//                     currentStreak++;
//                 }

//                 longestStreak = max(longestStreak, currentStreak);
//             }
//         }

//         return longestStreak;
//     }
// };