#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int i,j,n=words.size(), ans = 0;

        for(i=0;i<n-1;i++){
            string prefixAndSuffix = words[i];
            int temp = prefixAndSuffix.length();
            for(j=i+1;j<n;j++){
                if(words[j].length()>=temp&&words[j].starts_with(prefixAndSuffix)&&words[j].ends_with(prefixAndSuffix)){
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    Solution obj;
    cout << obj.countPrefixSuffixPairs(words) << endl;
    return 0;
}