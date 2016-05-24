/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 代码一 递归版
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        inorder(result,root);
        
        return result;
    }
    
    void inorder(vector<int>& result, TreeNode* node){
        if(node==NULL) return;
        
        
        if(node->left!=NULL) inorder(result,node->left);
        result.push_back(node->val);
        if(node->right!=NULL) inorder(result,node->right);
    }
};