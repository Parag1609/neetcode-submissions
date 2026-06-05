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
    int sum;
    void numbers(TreeNode* root,int num){
        if(!root){
            return;
        }
        num=num*10+root->val;
        if(!root->left && !root->right)sum+=num;
        numbers(root->left,num);
        numbers(root->right,num);
        return;
    }
    int sumNumbers(TreeNode* root) {
        sum=0;
        numbers(root,0);
        return sum;
    }
};