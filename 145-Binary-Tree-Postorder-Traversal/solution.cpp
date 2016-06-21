/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// // 代码一  栈  O(n)  O(n)
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> result;
//         if(root==nullptr) return result;
        
//         stack<TreeNode*> s;
//         TreeNode *p=root, *q=nullptr;
        
//         do{
//             while(p!=nullptr){
//                 s.push(p);
//                 p=p->left;
//             }    
            
//             q=nullptr;
            
//             while(!s.empty()){
//                 p=s.top();
//                 s.pop();
                
//                 if(p->right==q){ // 右孩子不存在或已被访问
//                     result.push_back(p->val);
//                     q=p;
//                 }
//                 else{
//                     s.push(p);
//                     p=p->right;
//                     break;
//                 }
//             }
//         }while(!s.empty());
        
//         return result;
//     }
// };


// 代码二 Morris O(n)  O(1)
/*
后续遍历稍显复杂，需要建立一个临时节点dump，令其左孩子是root。并且还需要一个子过程，就是倒序输出某两个节点之间路径上的各个节点。
步骤：
当前节点设置为临时节点dump。
1. 如果当前节点的左孩子为空，则将其右孩子作为当前节点。
2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。倒序输出从当前节点的左孩子到该前驱节点这条路径上的所有节点。当前节点更新为当前节点的右孩子。
3. 重复以上1、2直到当前节点为空。
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode dummy(-1);
        dummy.left=root;
        TreeNode *cur=&dummy, *pre=nullptr;
        
        while(cur!=nullptr){
            if(cur->left==nullptr){
                cur=cur->right;
            }
            else{
                pre=cur->left;
                while(pre->right!=nullptr&&pre->right!=cur){
                    pre=pre->right;
                }
                
                if(pre->right==nullptr){
                    pre->right=cur;
                    cur=cur->left;
                }
                else{
                    insertReverse(result,cur->left,pre);
                    pre->right=nullptr;
                    cur=cur->right;
                }
            }
        }
        
        return result;
    }
    
    
    void insertReverse(vector<int>& result, TreeNode* from, TreeNode* to){
        reverse(from,to);
        TreeNode *p=to;
        while(true){
            result.push_back(p->val);
            if(p==from){
                break;
            }
            p=p->right;
        }
        reverse(to,from);
    }
    
    
    void reverse(TreeNode *from, TreeNode *to){
        if(from==to) return;
        
        TreeNode *x=from, *y=from->right, *z;
        while(true){
            z=y->right;
            y->right=x;
            x=y;
            y=z;
            if(x==to) break;
        }
    }
};