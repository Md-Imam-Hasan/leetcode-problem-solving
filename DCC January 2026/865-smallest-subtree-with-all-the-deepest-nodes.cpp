/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
      pair<int, TreeNode*> dfs(TreeNode* root) {
          if (!root)
              return {0, nullptr};
  
          auto [leftLevel, leftNode] = dfs(root->left);
          auto [rightLevel, rightNode] = dfs(root->right);
  
          if (leftLevel == rightLevel) {
              return {leftLevel + 1, root};
          } else if (leftLevel > rightLevel) {
              return {leftLevel + 1, leftNode};
          } else {
              return {rightLevel + 1, rightNode};
          }
      }
      TreeNode* subtreeWithAllDeepest(TreeNode* root) { return dfs(root).second; }
  };