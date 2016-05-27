/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// // Wrong Answer [1,2]
// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         if(root==nullptr) return 0;
        
//         return min(minDepth(root->left),minDepth(root->right))+1;
//     }
// };


// // 代码一 递归版 O(n)  O(logn)
// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         return minDepth(root,false);
//     }
    
//     int minDepth(TreeNode* root, bool hasbrother){
//         if(root==nullptr) return hasbrother?INT_MAX:0;
        
//         return min(minDepth(root->left,root->right!=nullptr),minDepth(root->right,root->left!=nullptr))+1;
//     }
// };


// 代码二 迭代版 O(n)  O(logn)
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        
        int result=INT_MAX;
        
        stack<pair<TreeNode*,int>> s;
        s.push(make_pair(root,1));
        
        while(!s.empty()){
            auto node=s.top().first;
            auto depth=s.top().second;
            s.pop();
            
            if(node->left==nullptr&&node->right==nullptr){ //遍历到叶节点
                result=min(result,depth);
            }
            
            if(node->left&&result>depth){ // 剪枝
                s.push(make_pair(node->left,depth+1));
            }
            
            if(node->right&&result>depth){
                s.push(make_pair(node->right,depth+1));
            }
        }
        
        return result;
    }
};
