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
    void flatten(TreeNode* root) {
          TreeNode* curr = root;     //BY USING MORRIS TRAVEL
        while(curr){
            if(curr->left){    
                TreeNode* pred = curr->left;   //make pred curr's left
                while(pred->right){
                    pred = pred->right;   //go to the extreme right from pred
                }
                pred->right = curr->right;  //assign pred's right to curr's right so that nodes are
                curr->right = curr->left;  //not lost and point curr'right to curr's left to make ll
                curr->left = NULL;      //and make curr's left null
            }
            curr = curr->right;  //and then move to next node of curr
        }   
    }
};