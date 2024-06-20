#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
  stack<int> st;
  vector<int> v;
  int n = 0, m = 0;
  MinStack()
  {
  }

  void push(int val)
  {
    st.push(val);
    if (n != 0)
    {
      val = min(val, v[n - 1]);
    }
    if (m == n)
    {
      v.push_back(val);
      m++;
    }
    else
    {
      v[n] = val;
    }
    n++;
  }

  void pop()
  {
    st.pop();
    n--;
  }

  int top()
  {
    return st.top();
  }

  int getMin()
  {
    return v[n - 1];
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */