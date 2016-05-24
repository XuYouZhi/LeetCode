/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// // 代码一 递归版
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
        
//         inorder(result,root);
        
//         return result;
//     }
    
//     void inorder(vector<int>& result, TreeNode* node){
//         if(node==NULL) return;
        
        
//         if(node->left!=NULL) inorder(result,node->left);
//         result.push_back(node->val);
//         if(node->right!=NULL) inorder(result,node->right);
//     }
// };


// 代码二 使用栈 迭代 O(n) O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<const TreeNode*> s;
        const TreeNode* p=root;
        
        while(!s.empty()||p!=nullptr){
            if(p!=nullptr){
                s.push(p);
                p=p->left;
            }
            else{
                p=s.top();
                s.pop();
                result.push_back(p->val);
                p=p->right;
            }
        }
        
        return result;
    }
};