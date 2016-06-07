/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// // 代码一 迭代 O(n)
// class Solution {
// public:
//     void connect(TreeLinkNode *root) {
//         if(root==nullptr) return;
        
//         deque<TreeLinkNode*> deque_treelinknode;
        
//         deque_treelinknode.push_back(root);
        
//         int level_size=1;
//         vector<TreeLinkNode*> level;
        
//         while(deque_treelinknode.size()){
//             TreeLinkNode* node=deque_treelinknode.front();
//             deque_treelinknode.pop_front();
            
//             level.push_back(node);
            
//             if(node->left!=nullptr) deque_treelinknode.push_back(node->left);
            
//             if(node->right!=nullptr) deque_treelinknode.push_back(node->right);
            
//             if(level.size()>=level_size){
//                 for(int i=0;i<level.size()-1;++i){
//                     level[i]->next=level[i+1];
//                 }
//                 level[level.size()-1]=nullptr;
                
//                 level.clear();
//                 level_size=deque_treelinknode.size();
//             }
            
//         }
//     }
// };



// // 代码二 递归 O(n) O(1)
// class Solution {
// public:
//     void connect(TreeLinkNode *root) {
//         if(root==nullptr) return;
        
//         TreeLinkNode dummy(-1);
//         for(TreeLinkNode *cur=root, *pre=&dummy;cur;cur=cur->next){
//             if(cur->left!=nullptr){
//                 pre->next=cur->left;
//                 pre=pre->next;
//             }
//             if(cur->right!=nullptr){
//                 pre->next=cur->right;
//                 pre=pre->next;
//             }
//         }
        
//         connect(dummy.next);
//     }
// };



// 代码三 迭代 O(n) O(1)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while(root){
            TreeLinkNode *next=nullptr;
            TreeLinkNode *prev=nullptr;
            
            for(;root;root=root->next){
                if(!next) next=root->left?root->left:root->right;
                
                if(root->left){
                    if(prev) prev->next=root->left;
                    prev=root->left;
                }
                
                if(root->right){
                    if(prev) prev->next=root->right;
                    prev=root->right;
                }
            }
            
            root=next;
        }
    }
};
