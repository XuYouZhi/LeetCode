/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 代码一 递归 O(n) O(logn)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        
        flatten(root->left);
        flatten(root->right);
        
        if(root->left==nullptr) return;
        
        TreeNode *p=root->left;
        while(p->right) p=p->right;
        p->right=root->right;
        root->right=root->left;
        root->left=nullptr;
    }
};