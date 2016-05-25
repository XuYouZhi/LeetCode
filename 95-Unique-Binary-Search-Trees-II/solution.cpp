/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 代码一 
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode*>{};
        return generate(1,n);
    }
    
    vector<TreeNode*> generate(int start,int end){
        vector<TreeNode*> sub_tree;
        
        if(start>end){
            sub_tree.push_back(nullptr);
            return sub_tree;
        }
        
        for(int k=start;k<=end;++k){
            vector<TreeNode*> left_subs=generate(start,k-1);
            vector<TreeNode*> right_subs=generate(k+1,end);
            for(int i=0;i<left_subs.size();++i){
                for(int j=0;j<right_subs.size();++j){
                    TreeNode *node=new TreeNode(k);
                    node->left=left_subs[i];
                    node->right=right_subs[j];
                    sub_tree.push_back(node);
                }
            }
        }
        
        return sub_tree;
    }
};