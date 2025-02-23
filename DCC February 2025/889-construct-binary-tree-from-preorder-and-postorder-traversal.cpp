#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
      TreeNode* builtTree(vector<int>& preorder, vector<int>& postorder,
                          int& preIndex, int start, int end, int size) {
          if (preIndex >= size || start > end) {
              return nullptr;
          }
  
          TreeNode* root = new TreeNode(preorder[preIndex]);
          ++preIndex;
  
          if (start == end) {
              return root;
          }
  
          int i;
          for (i = start; i <= end; i++) {
              if (postorder[i] == preorder[preIndex])
                  break;
          }
  
          if (i <= end) {
              root->left =
                  builtTree(preorder, postorder, preIndex, start, i, size);
              root->right =
                  builtTree(preorder, postorder, preIndex, i + 1, end - 1, size);
          }
          return root;
      }
      TreeNode* constructFromPrePost(vector<int>& preorder,
                                     vector<int>& postorder) {
          int preIndex = 0;
          int size = preorder.size();
  
          return builtTree(preorder, postorder, preIndex, 0, size - 1, size);
      }
  };