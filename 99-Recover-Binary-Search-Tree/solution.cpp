/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 思路：中序遍历后，从前往后找到第一个逆序的位置，然后从后往前找到第二个逆序的位置，交换即可
// O(n)  O(1)
class Solution {
private:
    TreeNode* first=nullptr;
    TreeNode* second=nullptr;
public:
    void recoverTree(TreeNode* root) {
        inorderTraversal(root);
        swap(first->val,second->val);
    }
    
    void inorderTraversal(TreeNode* root) {
        TreeNode *cur=root;
        TreeNode *prev=nullptr; // 前驱节点
        TreeNode *p=nullptr;
        
        while(cur!=nullptr){
            if(cur->left==nullptr){
                if(p!=nullptr&&first==nullptr&&p->val>=cur->val){
                    first=p;
                }
                
                if(p!=nullptr&&first!=nullptr&&p->val>=cur->val){
                    second=cur;
                }
                
                p=cur;
                cur=cur->right;
            }
            else{
                prev=cur->left;
                while(prev->right!=nullptr&&prev->right!=cur) prev=prev->right;
                
                if(prev->right==nullptr){
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    prev->right=nullptr;
                    
                    if(p!=nullptr&&first==nullptr&&p->val>=cur->val){
                        first=p;
                    }
                    
                    if(p!=nullptr&&first!=nullptr&&p->val>=cur->val){
                        second=cur;
                    }
                    
                    p=cur;
                    cur=cur->right;
                }
            }
        }
    }
};