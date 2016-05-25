/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// // 错误答案，没有考虑到右子树中所有元素都应该大于根节点，例如 [10,5,15,null,null,6,20]
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         if(root==nullptr) return true; 
        
//         if(root->left){
//             if(!isValidBST(root->left)||root->left->val>=root->val) return false;
//         }
        
//         if(root->right){
//             if(!isValidBST(root->right)||root->right->val<=root->val) return false;
//         }
        
//         return true;
//     }
// };


// O(n)  O(logn)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
    
    bool isValidBST(TreeNode* root, long int lower, long int upper){
        if(root==nullptr) return true;
        
        return root->val>lower&&root->val<upper&&isValidBST(root->left,lower,root->val)&&isValidBST(root->right,root->val,upper);
    }
};