#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int findGCD(int arr[], int n)
    {
      int result = arr[0];
      for (int i = 1; i < n; i++)
      {
        result = gcd(arr[i], result);
    
        if(result == 1)
        {
        return 1;
        }
      }
      return result;
    }
    
    int findlcm(int arr[], int n)
    {
        int ans = arr[0];
    
        for (int i = 1; i < n; i++)
            ans = (((arr[i] * ans)) /
                    (gcd(arr[i], ans)));
    
        return ans;
    }

    int product(int ar[], int n)
    {
        int result = 1;
        for (int i = 0; i < n; i++)
            result = result * ar[i];
        return result;
    }
    int maxLength(vector<int>& nums) {
    int len = nums.size(), ans = 0;
    for(int i = 1; i <= len; i++) {
        for(int j = 0; j <= len - i; j++) {
            vector<int> ar(nums.begin() + j, nums.begin() + j + i);
            int prod = product(ar.data(), i);
            int lcm_result = findlcm(ar.data(), i);
            int gcd_result = findGCD(ar.data(), i);
            if(prod == lcm_result * gcd_result){
                ans = max(ans, i);
            }
        }
    }
    return ans;
}

};