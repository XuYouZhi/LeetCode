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
    int maxDepth(TreeNode* root) {
        return maxDepth(root,0);
    }
    
    int maxDepth(TreeNode* root, int depth){
        if(root==nullptr) return depth;
        ++depth;
        return max(maxDepth(root->left,depth),maxDepth(root->right,depth));
    }
};