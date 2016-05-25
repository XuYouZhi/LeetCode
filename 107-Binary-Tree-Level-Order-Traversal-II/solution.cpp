/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 和Binary Tree Level Order Traversal I一样，只是加一行reverse
// 代码一 迭代
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }
        
        deque<TreeNode*> deque_treenode;
        
        deque_treenode.push_back(root);
        
        int level_size=1;
        vector<int> level;
        
        while(deque_treenode.size()){
            TreeNode* node=deque_treenode.front();
            deque_treenode.pop_front();
            
            level.push_back(node->val);
            
            if(node->left!=NULL){
                deque_treenode.push_back(node->left);
            }
            
            if(node->right!=NULL){
                deque_treenode.push_back(node->right);
            }
            
            if(level.size()>=level_size){
                result.push_back(level);
                level.clear();
                level_size=deque_treenode.size();
            }
        }
        
        reverse(result.begin(),result.end());
        return result;
    }
};