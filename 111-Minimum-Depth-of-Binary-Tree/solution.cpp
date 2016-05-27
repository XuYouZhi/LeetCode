/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// // Wrong Answer [1,2]
// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         if(root==nullptr) return 0;
        
//         return min(minDepth(root->left),minDepth(root->right))+1;
//     }
// };


// 代码一 递归版 O(n)  O(logn)
class Solution {
public:
    int minDepth(TreeNode* root) {
        return minDepth(root,false);
    }
    
    int minDepth(TreeNode* root, bool hasbrother){
        if(root==nullptr) return hasbrother?INT_MAX:0;
        
        return min(minDepth(root->left,root->right!=nullptr),minDepth(root->right,root->left!=nullptr))+1;
    }
};