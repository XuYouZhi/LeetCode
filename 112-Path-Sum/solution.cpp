/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// // 代码一 递归 O(n) O(logn)
// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int sum) {
//         if(root==NULL){
//             return false;
//         }
        
//         int current_sum=0;
        
//         return hasPathSum(root,sum,current_sum);
        
//     }
    
//     bool hasPathSum(TreeNode*root, int sum, int current_sum){
//         current_sum+=root->val;
        
//         bool isleaf=root->left==NULL&&root->right==NULL;
        
//         if(current_sum==sum&&isleaf){
//             return true;
//         }
//         else if(isleaf){
//             return false;
//         }
        
//         bool left_has=false,right_has=false;
        
//         if(root->left!=NULL){
//             left_has=hasPathSum(root->left,sum,current_sum);
//         }
        
//         if(root->right!=NULL){
//             right_has=hasPathSum(root->right,sum,current_sum);
//         }
        
//         return (left_has||right_has);
        
//     }
// };


// 代码二 更简洁的代码  递归 O(n) O(logn)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr) return false;
        
        if(root->left==nullptr&&root->right==nullptr){ //leaf
            return sum==root->val;
        }
        
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
};

