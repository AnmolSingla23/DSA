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
    
    bool solve(TreeNode* root,int key,int sum){
        if(!root)
            return false;
        
        if(!root->left && !root->right){
            sum += root->val;
            if(sum == key)
                return true;
            sum -= root->val;
        }
        
        
        bool left = solve(root->left,key,sum + root->val);
        bool right = solve(root->right,key,sum + root->val);
        sum -= root->val;
        return left || right;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        int sum = 0;
        return solve(root,targetSum,sum);
    }
};