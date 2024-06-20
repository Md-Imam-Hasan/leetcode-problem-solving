#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  void solve(string op, int open, int close, vector<string> ans)
  {
    if (open == close && open != 0)
    {
      op += '(';
      open--;
      solve(op, open, close, ans);
    }
    else if (open == 0 && close > 0)
    {
      op += ')';
      close--;
      solve(op, open, close, ans);
    }
    else if (open == close && open == 0)
    {
      ans.push_back(op);
      return;
    }
    else if (open != close)
    {
      string op1 = op + "(";
      string op2 = op + ")";
      int open1 = open - 1;
      solve(op1, open1, close, ans);
      int close1 = close - 1;
      solve(op2, open, close1, ans);
    }
  }
  vector<string> generateParenthesis(int n)
  {
    vector<string> ans;
    int open = n, close = n;
    string op = "";
    solve(op, open, close, ans);

    return ans;
  }
};