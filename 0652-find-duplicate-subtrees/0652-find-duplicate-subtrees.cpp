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
    string dfs(vector<TreeNode*> &ans,unordered_map<string,int> &mp, TreeNode* root){

        if(!root) return "N";  //if leaf node mark null by n

        string curr = to_string(root->val) + "," + dfs(ans,mp,root->left) + "," + dfs(ans,mp,root->right);
        //add curr node then traverse to left and right side and create a string
        if(mp.find(curr) != mp.end()){  //if the string is already present in the map
            if(mp[curr] == 1)   //and its count is 1 then it means we have found the duplicate store it
                ans.push_back(root);
            mp[curr]++;   // then increase the count of the string
        }
         else{
                mp[curr] = 1;   //if the string is not present then initiate it
            }
        return curr;            //return the string
         
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode*> ans;
        unordered_map<string,int> mp;  //store the paths in string format and store it in map

        dfs(ans,mp,root);
        return ans;
    }
};