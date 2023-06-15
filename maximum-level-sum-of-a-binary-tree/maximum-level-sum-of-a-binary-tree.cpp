

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> qNode;
        queue<int> qLevel;
        int maxLevel = 0, maxSum = INT_MIN;
        int lastLevel = 1, lastSum = 0;
        TreeNode* node;
        
        qNode.push(root);
        qLevel.push(lastLevel);
        
        while(!qNode.empty()){
            node = qNode.front();
            // cout << node->val << endl;
            qNode.pop();
            
            lastLevel = qLevel.front();
            qLevel.pop();
            
            lastSum += node->val;
            
            if(node->left){
                qNode.push(node->left);
                qLevel.push(lastLevel+1);
            }
            
            if(node->right){
                qNode.push(node->right);
                qLevel.push(lastLevel+1);
            }
            
            //clean up before entering new level
            if(lastLevel != qLevel.front()){
                if(lastSum > maxSum){
                    maxSum = lastSum;
                    maxLevel = lastLevel;
                }
                lastSum = 0;
            }
        }
        
        return maxLevel;
    }
};

/* 2nd */
/*

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* node;
        int levelSize;
        int curLevel = 1;
        int maxSum = INT_MIN, maxLevel = -1;
        int levelSum = 0;
        
        q.push(root);
        
        while(!q.empty()){
            levelSize = q.size();
            for(int i = 0; i < levelSize; i++){
                node = q.front();
                q.pop();
                
                if(node->left){
                    q.push(node->left);
                }
                
                if(node->right){
                    q.push(node->right);
                }
                
                levelSum += node->val;
            }
            
            //clean up before going to next level
            if(levelSum > maxSum){
                maxSum = levelSum;
                maxLevel = curLevel;
            }
            levelSum = 0;  
            curLevel++;
        }
        
        return maxLevel;
    }
};
*/

/* 3rd */
/*
//DFS

class Solution {
public:
    //iterate tree and fill levelSums
    void dfs(TreeNode* node, vector<int>& levelSums, int level){
        if(!node) return;
        //ex: levelSums is empty, we need to make its length 1 so that we can set levelSums[0] as node->val
        if(level == levelSums.size()){
            levelSums.push_back(node->val);
        }else{
            levelSums[level] += node->val;
        }
        
        if(node->left){
            dfs(node->left, levelSums, level+1);
        }
        if(node->right){
            dfs(node->right, levelSums, level+1);
        }
    };
    
    int maxLevelSum(TreeNode* root) {
        //levelSums[0]: the sum of nodes' values in level 0+1=1
        vector<int> levelSums;

        //pretend the first level is level 0
        //later will add 1 to convert it to the real level
        dfs(root, levelSums, 0);
        
        //max_element: Returns an iterator pointing to the element with the largest value in the range [first,last).
        return distance(levelSums.begin(), 
                max_element(levelSums.begin(), levelSums.end())) + 1;
    }
};

*/