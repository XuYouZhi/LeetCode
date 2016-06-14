/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// // 代码一 O(n) O(logn)
// class Solution {
// public:
//     int sumNumbers(TreeNode* root) {
//         int result=0;
//         if(root==nullptr) return 0;
//         int sum=0;
//         sumNumbers(root,result,sum);
//         return result;
//     }
    
//     void sumNumbers(TreeNode* root, int& result, int sum){
//         sum+=root->val;
        
//         if(root->left==nullptr&&root->right==nullptr){
//             result+=sum;
//             return;
//         }
        
//         if(root->left!=nullptr){
//             sumNumbers(root->left,result,sum*10);
//         }
        
//         if(root->right!=nullptr){
//             sumNumbers(root->right,result,sum*10);
//         }
//     }
// };


// 代码二  精简版  O(n) O(logn)
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
    
private:
    int dfs(TreeNode* root, int sum){
        if(root==nullptr) return 0;
        if(root->left==nullptr&&root->right==nullptr){
            return sum*10+root->val;
        }
        
        return dfs(root->left,sum*10+root->val)+dfs(root->right,sum*10+root->val);
    }
};