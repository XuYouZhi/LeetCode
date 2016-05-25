/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return paths;
        }
        
        int current_sum=0;
        vector<int >path;
        pathSum(root,sum,current_sum,path);
        
        return paths;
    }
    
    void pathSum(TreeNode*root, int sum, int current_sum,vector<int>& path){
        path.push_back(root->val);
        
        current_sum+=root->val;
        
        bool isleaf=root->left==NULL&&root->right==NULL;
        
        if(current_sum==sum&&isleaf){
            paths.push_back(path);
        }
        
        if(root->left!=NULL){
            pathSum(root->left,sum,current_sum,path);
        }
        
        if(root->right!=NULL){
            pathSum(root->right,sum,current_sum,path);
        }
        
        path.pop_back();
    }
    
private:
    vector<vector<int>> paths;
};