#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  bool isValidSudoku(vector<vector<char>> &board)
  {
    for (int i = 0; i < 9; i++)
    {
      vector<int> check(9, 0);
      for (int j = 0; j < 9; j++)
      {
        char c = board[i][j];
        if (c >= '1' && c <= '9')
        {
          int num = c - '0';
          check[num - 1]++;
          if (check[num - 1] > 1)
          {
            return false;
          }
        }
      }
    }

    for (int i = 0; i < 9; i++)
    {
      vector<int> check(9, 0);
      for (int j = 0; j < 9; j++)
      {
        char c = board[j][i];
        if (c >= '1' && c <= '9')
        {
          int num = c - '0';
          check[num - 1]++;
          if (check[num - 1] > 1)
          {
            return false;
          }
        }
      }
    }

    for (int h = 0; h < 9; h += 3)
    {
      for (int i = 0; i < 9; i += 3)
      {
        vector<int> check(9, 0);
        for (int j = h; j < h + 3 && j < 9; j++)
        {
          for (int k = i; k < i + 3 && k < 9; k++)
          {
            char c = board[j][k];
            if (c >= '1' && c <= '9')
            {
              int num = c - '0';
              check[num - 1]++;
              if (check[num - 1] > 1)
              {
                return false;
              }
            }
          }
        }
      }
    }

    return true;
  }
};
