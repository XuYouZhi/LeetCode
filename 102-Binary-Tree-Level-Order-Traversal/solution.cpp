/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// // 代码一 迭代版  利用队列  O(n)
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> result;
//         if(root==NULL){
//             return result;
//         }
        
//         deque<TreeNode*> deque_treenode;
        
//         deque_treenode.push_back(root);
        
//         int level_size=1;
//         vector<int> level;
        
//         while(deque_treenode.size()){
//             TreeNode* node=deque_treenode.front();
//             deque_treenode.pop_front();
            
//             level.push_back(node->val);
            
//             if(node->left!=NULL){
//                 deque_treenode.push_back(node->left);
//             }
            
//             if(node->right!=NULL){
//                 deque_treenode.push_back(node->right);
//             }
            
//             if(level.size()>=level_size){
//                 result.push_back(level);
//                 level.clear();
//                 level_size=deque_treenode.size();
//             }
//         }
        
//         return result;
//     }
// };


// 代码二 递归版 O(n)  O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        traverse(root,1,result);
        return result;
    }
    
    void traverse(TreeNode* root, size_t level, vector<vector<int>>& result){
        if(!root) return;
        
        if(level>result.size()){
            result.push_back(vector<int>());
        }
        
        result[level-1].push_back(root->val);
        
        traverse(root->left,level+1,result);
        traverse(root->right,level+1,result);
    }
};