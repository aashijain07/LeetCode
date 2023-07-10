/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
         if(!root) return 0;
        return f(root);
    }
     int f(TreeNode* root){
       if(root == NULL) return INT_MAX;
      if(!root->left && !root->right) return 1;

       int lh = f(root->left);
       int rh = f(root->right);
       return 1 + min(lh,rh); 
    }
};