class Solution {
public:
    int calc(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;

        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        v.push_back(1);
        int ans = 1;

        for (int i = 3; i <= n; i++) {
            ans = v[i - 3] + v[i - 2] + v[i - 1];
            v.push_back(ans);
        }

        return ans;
    }
    int tribonacci(int n) { return calc(n); }
};