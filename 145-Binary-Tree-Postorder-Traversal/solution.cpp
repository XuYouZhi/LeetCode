/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 代码一  栈  O(n)  O(n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==nullptr) return result;
        
        stack<TreeNode*> s;
        TreeNode *p=root, *q=nullptr;
        
        do{
            while(p!=nullptr){
                s.push(p);
                p=p->left;
            }    
            
            q=nullptr;
            
            while(!s.empty()){
                p=s.top();
                s.pop();
                
                if(p->right==q){ // 右孩子不存在或已被访问
                    result.push_back(p->val);
                    q=p;
                }
                else{
                    s.push(p);
                    p=p->right;
                    break;
                }
            }
        }while(!s.empty());
        
        return result;
    }
};