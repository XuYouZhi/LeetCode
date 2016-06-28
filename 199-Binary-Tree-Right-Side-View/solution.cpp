/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// // Wrong Answer 想情况太简单  没考虑到当右边的短露出左边的树的情况
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> result;
        
//         TreeNode *p=root;
//         while(p){
//             result.push_back(p->val);
//             p=p->right;
//         }
        
//         return result;
//     }
// };


// // 代码一 层级遍历  压入每层的最后一个元素  Breadth-First Search
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> result;
//         if(root==nullptr) return result;
        
//         deque<TreeNode*> deque_treenode;
        
//         deque_treenode.push_back(root);
//         int level_size=1;
//         int level_count=0;
//         int right;
//         while(deque_treenode.size()){
//             TreeNode *node=deque_treenode.front();
//             deque_treenode.pop_front();
            
//             right=node->val;
//             ++level_count;
            
//             if(node->left!=nullptr) deque_treenode.push_back(node->left);
//             if(node->right!=nullptr) deque_treenode.push_back(node->right);
            
//             if(level_count>=level_size){
//                 result.push_back(right);
//                 level_count=0;
//                 level_size=deque_treenode.size();
//             }
//         }
        
//         return result;
//     }
// };



// 代码二 深度遍历
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int maxdepth=0;
        if(root==nullptr) return result;
        
        rightSideView(root,result,maxdepth,1);
        
        return result;
    }
    
    void rightSideView(TreeNode* root, vector<int>& result, int& maxdepth, int depth){
        if(depth>maxdepth){
            maxdepth=depth;
            result.push_back(root->val);
        }
        
        if(root->right!=nullptr) rightSideView(root->right, result, maxdepth, depth+1);
        if(root->left!=nullptr) rightSideView(root->left, result, maxdepth, depth+1);
    }

};