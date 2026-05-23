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
    void fill(TreeNode* root,int targetSum,int sum,bool &var){
        if(!root || var)return;
        sum+=root->val;
        if(!root->left && !root->right){
            if(sum==targetSum){
                var=true;
            }
            return;
        }
        fill(root->left,targetSum,sum,var);
        fill(root->right,targetSum,sum,var);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool var=false;
        fill(root,targetSum,sum,var);
        return var;
    }
};