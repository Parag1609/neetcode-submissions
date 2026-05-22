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
    int sum=INT_MIN;
    int maxSum(TreeNode* root){
        if(root==NULL)return 0;
        int lsum=maxSum(root->left);
        int rsum=maxSum(root->right);
        sum=max(sum,root->val+max(0,lsum)+max(0,rsum));
        return root->val + max(max(0, lsum),  max(0, rsum));
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return sum;
    }
};
