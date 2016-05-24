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


// // 代码二 使用栈 迭代 O(n) O(n)
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         stack<const TreeNode*> s;
//         const TreeNode* p=root;
        
//         while(!s.empty()||p!=nullptr){
//             if(p!=nullptr){
//                 s.push(p);
//                 p=p->left;
//             }
//             else{
//                 p=s.top();
//                 s.pop();
//                 result.push_back(p->val);
//                 p=p->right;
//             }
//         }
        
//         return result;
//     }
// };


// 代码二 Morris O(n) O(1)
/*
1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。
3. 重复以上1、2直到当前节点为空。
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode *cur=root;
        TreeNode *prev=nullptr; // 前驱节点
        
        while(cur!=nullptr){
            if(cur->left==nullptr){
                result.push_back(cur->val);
                cur=cur->right;
            }
            else{
                // 寻找前驱
                prev=cur->left;
                while(prev->right!=NULL&&prev->right!=cur){
                    prev=prev->right;
                }
                
                if(prev->right==NULL){ //2.a)
                    prev->right=cur;
                    cur=cur->left;
                }
                else{ //2.b)
                    prev->right=NULL;
                    result.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        
        return result;
    }
};