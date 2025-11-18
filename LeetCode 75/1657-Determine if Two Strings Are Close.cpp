class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;
        set<char> setA(word1.begin(), word1.end());
        set<char> setB(word2.begin(), word2.end());
        if (setA != setB)
            return false;

        unordered_map<char, int> freq1, freq2;
        vector<int> v1, v2;

        for (char x : word1) {
            freq1[x]++;
        }

        for (char x : word2) {
            freq2[x]++;
        }

        for (auto& x : freq1) {
            v1.push_back(x.second);
        }

        for (auto& x : freq2) {
            v2.push_back(x.second);
        }

        if (v1.size() != v2.size())
            return false;

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i])
                return false;
        }

        return true;
    }
};