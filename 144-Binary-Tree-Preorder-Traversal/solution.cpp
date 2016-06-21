/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// // 代码一 使用栈 O(n) O(n)
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         if(root==nullptr){
//             return result;
//         }
        
//         stack<TreeNode*> s;
//         s.push(root);
//         while(!s.empty()){
//             TreeNode* p=s.top();
//             s.pop();
//             result.push_back(p->val);
            
//             if(p->right!=nullptr){
//                 s.push(p->right);
//             }
            
//             if(p->left!=nullptr){
//                 s.push(p->left);
//             }
            
//         }
//         return result;
//     }
// };




// 代码二 Mirrors  O(n) O(1)
/*
步骤：
1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。输出当前节点（在这里输出，这是与中序遍历唯一一点不同）。当前节点更新为当前节点的左孩子。
   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。当前节点更新为当前节点的右孩子。
3. 重复以上1、2直到当前节点为空。
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode *cur=root;
        TreeNode *pre=nullptr;
        
        while(cur!=nullptr){
            if(cur->left==nullptr){
                result.push_back(cur->val);
                cur=cur->right;
            }
            else{
                //寻找前驱
                pre=cur->left;
                while(pre->right!=nullptr&&pre->right!=cur){
                    pre=pre->right;
                }
                
                if(pre->right==nullptr){
                    result.push_back(cur->val);
                    pre->right=cur;
                    cur=cur->left;
                }
                else{
                    pre->right=nullptr;
                    cur=cur->right;
                }
            }
        }
        
        return result;
    }
};
