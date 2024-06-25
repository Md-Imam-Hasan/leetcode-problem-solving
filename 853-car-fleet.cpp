#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, double>> v;

        int n = position.size(), cnt = 0;

        for (int i = 0; i < n; i++)
        {
            int dist = target - position[i];
            double time = (double)dist / speed[i];
            v.push_back({position[i], time});
        }

        sort(v.begin(), v.end());

        double cuuTime = 0.0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i].second > cuuTime)
            {
                cnt++;
                cuuTime = v[i].second;
            }
        }

        return cnt;
    }
};