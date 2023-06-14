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
    int last = INT_MIN/2;
    int ans = INT_MAX;
    
    void inOrder(TreeNode* node){
        if(node->left) inOrder(node->left);
        ans = min(ans, node->val - last);
        last = node->val;
        if(node->right) inOrder(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};
