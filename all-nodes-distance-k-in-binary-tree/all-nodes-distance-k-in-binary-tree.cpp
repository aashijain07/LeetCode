/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>mp;
    void traverse(TreeNode* root, TreeNode* parent)
    {
        if(root == NULL)
            return ;
        mp[root] = parent;
        traverse(root->left,root);
        traverse(root->right,root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // TreeNode* node = NULL;
        TreeNode* parent = NULL;

        //Traverse the tree to mark the parent of each node . Parent of root is NULL.
        traverse(root, parent);

        //visited set to keep track of all visited nodes
        unordered_set<int>vis;

        //for bfs traversal to find all nodes at distance k.
        queue<TreeNode*>q;
        q.push(target);
        
        int x=0;
        vector<int>ans;

        while(!q.empty())
        {
            int l = q.size();
            while(l--)
            {
                TreeNode* node = q.front();
                q.pop();

                //if this node is at distance k from target insert into ans vector
                if(x == k)
                    ans.push_back(node->val);
                
                // cout<<node->val<<" ";

                //markl visited
                vis.insert(node->val);

                //Check for left substree
                if(node->left && vis.find(node->left->val) == vis.end())
                {
                    q.push(node->left);
                }
                //check for right subtree
                if(node->right && vis.find(node->right->val) == vis.end())
                {
                    q.push(node->right);
                }
                //check for parents other not visited child backtrack
                if(mp[node] != NULL && vis.find(mp[node]->val) == vis.end())
                {
                    q.push(mp[node]);
                }
            }
            if(x == k)
            {
                return ans;
            }
            x++;
        }
        return {};
    }
};