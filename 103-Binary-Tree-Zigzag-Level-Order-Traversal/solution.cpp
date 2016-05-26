/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// // 代码一 迭代版 O(n)  O(n)
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> result;
//         if(root==nullptr) return result;
        
//         deque<TreeNode*> deque_treenode;
//         deque_treenode.push_back(root);
        
//         int level_count=1;
//         int level_size=1;
//         vector<int> level;
        
//         while(deque_treenode.size()){
//             TreeNode* node=deque_treenode.front();
//             deque_treenode.pop_front();
            
//             level.push_back(node->val);
            
//             if(node->left!=nullptr) deque_treenode.push_back(node->left);
//             if(node->right!=nullptr) deque_treenode.push_back(node->right);
            
//             if(level_size<=level.size()){
//                 if(level_count%2==0){
//                     reverse(level.begin(),level.end());
//                 }
//                 result.push_back(level);
//                 level.clear();
//                 level_size=deque_treenode.size();
//                 ++level_count;
//             }
//         }
        
//         return result;
//     }
// };


// 代码一 递归版 O(n)  O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        traverse(root,1,result,true);
        return result;
    }
    
    void traverse(TreeNode* root, size_t level, vector<vector<int>> &result, bool left_to_right){
        if(!root) return;
        
        if(level>result.size()){
            result.push_back(vector<int>());
        }
        
        if(left_to_right){
            result[level-1].push_back(root->val);
        }
        else{
            result[level-1].insert(result[level-1].begin(),root->val);
        }
        
        traverse(root->left,level+1,result,!left_to_right);
        traverse(root->right,level+1,result,!left_to_right);
    }
};