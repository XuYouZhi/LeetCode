/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// // 代码一 递归版 O(n) O(logn)
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if(root==NULL){
//             return true;
//         }
        
//         return isMirroEqual(root->left,root->right);
//     }
    
//     bool isMirroEqual(TreeNode* left_root, TreeNode* right_root){
//         if(left_root==NULL&&right_root==NULL){
//             return true;
//         }
//         else if(left_root==NULL&&right_root!=NULL){
//             return false;
//         }
//         else if(left_root!=NULL&&right_root==NULL){
//             return false;
//         }
//         else{
//             return left_root->val==right_root->val&&isMirroEqual(left_root->left,right_root->right)&&isMirroEqual(left_root->right,right_root->left);
//         }
        
//     }
// };



// 代码二 迭代版 O(n) O(logn)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        
        while(!s.empty()){
            auto p=s.top();s.pop();
            auto q=s.top();s.pop();
            
            if(!p&&!q) continue;
            if(!p||!q) return false;
            if(p->val!=q->val) return false;
            
            s.push(p->left);
            s.push(q->right);
            
            s.push(p->right);
            s.push(q->left);
        }
        
        return true;
    }
};

