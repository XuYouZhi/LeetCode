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
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p==NULL&&q==NULL){
//             return true;
//         }
//         else if(p==NULL&&q!=NULL){
//             return false;
//         }
//         else if(p!=NULL&&q==NULL){
//             return false;
//         }
//         else{
//             return p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
//         }
//     }
// };


// 代码一 迭代版 O(n) O(logn)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s;
        s.push(p);
        s.push(q);
        
        while(!s.empty()){
            p=s.top();s.pop();
            q=s.top();s.pop();
            
            if(!p&&!q) continue;
            if(!p||!q) return false;
            if(p->val!=q->val) return false;
            
            s.push(p->left);
            s.push(q->left);
            s.push(p->right);
            s.push(q->right);
        }
        
        return true;
    }
};


