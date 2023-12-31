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
    int mini = INT_MAX;
    int prev = INT_MAX;
    void inorder(TreeNode* root,vector<int> &ans){
        if(!root)
            return;
        
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    
    int solve(TreeNode* root){
        if(root->left)
            solve(root->left);
        
        if(prev!=INT_MAX)
            mini = min(mini,abs(root->val - prev));
        prev = root->val;
        
        if(root->right)
            solve(root->right);
        return mini;
    }
    
    int getMinimumDifference(TreeNode* root) {
        
        // vector<int> ans;
        // inorder(root,ans);
        // int mini = INT_MAX;
        // for(int i=1;i<ans.size();i++){
        //     if(ans[i] - ans[i-1] < mini)
        //         mini = ans[i]-ans[i-1];
        // }
        // return mini;
        solve(root);
        return mini;
    }
};