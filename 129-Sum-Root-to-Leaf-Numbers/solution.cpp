/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int result=0;
        if(root==nullptr) return 0;
        int sum=0;
        sumNumbers(root,result,sum);
        return result;
    }
    
    void sumNumbers(TreeNode* root, int& result, int sum){
        sum+=root->val;
        
        if(root->left==nullptr&&root->right==nullptr){
            result+=sum;
            return;
        }
        
        if(root->left!=nullptr){
            sumNumbers(root->left,result,sum*10);
        }
        
        if(root->right!=nullptr){
            sumNumbers(root->right,result,sum*10);
        }
    }
};