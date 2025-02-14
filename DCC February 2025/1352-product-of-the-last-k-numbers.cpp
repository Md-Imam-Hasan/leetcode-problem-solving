#include <bits/stdc++.h>

using namespace std;

class ProductOfNumbers {
  public:
      vector<int> numbers;
      vector<int> products;
      int lidx_of_zero = -1;
      int p = 1;
      ProductOfNumbers() {}
  
      void add(int num) {
          numbers.push_back(num);
          if (num == 0) {
              lidx_of_zero = numbers.size() - 1;
              products.push_back(num);
              p = 1;
          } else {
              p *= num;
              products.push_back(p);
          }
      }
  
      int getProduct(int k) {
          int n = numbers.size();
          int x = n - k - 1;
          if (x < lidx_of_zero) {
              return 0;
          } else if (x == lidx_of_zero) {
              return products[n - 1];
          } else {
              return products[n - 1] / products[x];
          }
      }
  };
  
  /**
   * Your ProductOfNumbers object will be instantiated and called as such:
   * ProductOfNumbers* obj = new ProductOfNumbers();
   * obj->add(num);
   * int param_2 = obj->getProduct(k);
   */