#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(int a, int b, std::string& sign) {
        if (sign == "+") {
            return a + b;
        } else if (sign == "-") {
            return b - a;
        } else if (sign == "*") {
            return a * b;
        } else if (sign == "/") {
            return floor(b / a);
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "/" || tokens[i] == "*" || tokens[i] == "-" ||
                tokens[i] == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int result = calculate(a, b, tokens[i]);
                st.push(result);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};