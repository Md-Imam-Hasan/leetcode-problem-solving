class Solution {
public:
    int maxVowels(string s, int k) {
        string vowels = "aeiou";
        int count = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (vowels.find(s[i]) != string::npos) {
                count++;
            }
            if (i >= k && vowels.find(s[i - k]) != string::npos) {
                count--;
            }
            if (i >= k - 1) {
                ans = max(ans, count);
            }
        }
        return ans;
    }
};