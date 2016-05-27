/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// O(n) O(logn)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return balanceHeight(root)>=0;
    }
    
    int balanceHeight(TreeNode* root){
        if(root==nullptr) return 0;
        
        int left=balanceHeight(root->left);
        int right=balanceHeight(root->right);
        
        if(left<0||right<0||abs(left-right)>1) return -1; //剪纸
        
        return max(left,right)+1;
    }
};