#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> st;
        vector<int> ans(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                st.pop();
                ans[st.top()] = i - st.top();
                if (st.empty())
                {
                    break;
                }
            }
            st.push(i);
        }
        return ans;
    }
};