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
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int>ans;
        if(!root)return ans;
        stack<TreeNode*>st;
        TreeNode* curr=root;
        TreeNode* last_visited=NULL;
        while(curr || !st.empty()){
            if(curr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                last_visited=st.top()->right;
                if(last_visited==NULL){
                    last_visited=st.top();
                    st.pop();
                    ans.push_back(last_visited->val);
                    while(!st.empty() && last_visited==st.top()->right){
                        last_visited=st.top();
                        st.pop();
                        ans.push_back(last_visited->val);
                    }
                }
                else{
                    curr=last_visited;
                }
            }
        }
        
        
        return ans;
    }
};