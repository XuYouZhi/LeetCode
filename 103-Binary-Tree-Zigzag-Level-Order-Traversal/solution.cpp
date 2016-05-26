/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 代码一 迭代版 O(n)  
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr) return result;
        
        deque<TreeNode*> deque_treenode;
        deque_treenode.push_back(root);
        
        int level_count=1;
        int level_size=1;
        vector<int> level;
        
        while(deque_treenode.size()){
            TreeNode* node=deque_treenode.front();
            deque_treenode.pop_front();
            
            level.push_back(node->val);
            
            if(node->left!=nullptr) deque_treenode.push_back(node->left);
            if(node->right!=nullptr) deque_treenode.push_back(node->right);
            
            if(level_size<=level.size()){
                if(level_count%2==0){
                    reverse(level.begin(),level.end());
                }
                result.push_back(level);
                level.clear();
                level_size=deque_treenode.size();
                ++level_count;
            }
        }
        
        return result;
    }
};