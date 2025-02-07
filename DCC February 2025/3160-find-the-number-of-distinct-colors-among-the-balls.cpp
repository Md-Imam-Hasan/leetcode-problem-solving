#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size(), i, temp_count = 0;
        unordered_map<int, int> vec, counts;
        vector<int> result;

        for (i = 0; i < n; i++) {
            int index = queries[i][0];
            int value = queries[i][1];
            if (vec[index] == 0) {
                vec[index] = value;
            } else {
                int oldValue = vec[index];
                vec[index] = value;

                if (--counts[oldValue] == 0) {
                    counts.erase(oldValue);
                    temp_count--;
                }
            }
            counts[value]++;
            if (counts[value] == 1)
                temp_count++;
            result.push_back(temp_count);
        }

        return result;
    }
};