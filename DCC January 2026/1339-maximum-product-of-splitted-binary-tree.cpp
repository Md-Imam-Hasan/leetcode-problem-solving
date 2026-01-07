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
      long long postorder(TreeNode* root) {
          if (!root)
              return 0;
  
          long long leftSum = postorder(root->left);
          long long rightSum = postorder(root->right);
  
          root->val = root->val + leftSum + rightSum;
          return root->val;
      }
  
      void postorderP(TreeNode* root, long long root_sum, long long& ans) {
          if (!root)
              return;
  
          postorderP(root->left, root_sum, ans);
          postorderP(root->right, root_sum, ans);
          long long temp = root_sum - root->val;
          ans = max(ans, temp * (root_sum - temp));
      }
      int maxProduct(TreeNode* root) {
          int MOD = 1000000007;
          long long root_sum = postorder(root);
          // cout << "root_sum: " << root_sum << endl;
          long long ans = INT_MIN;
          postorderP(root, root_sum, ans);
  
          return ans % MOD;
      }
  };