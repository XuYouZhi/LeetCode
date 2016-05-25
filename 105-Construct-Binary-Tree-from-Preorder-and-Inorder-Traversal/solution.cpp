/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// // 代码一, Time Consuming
// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         if(preorder.size()<1||inorder.size()<1){
//             return NULL;
//         }
        
//         int rootval=preorder.front();
//         TreeNode* root=new TreeNode(rootval);
        
//         vector<int> preleft,preright,inleft,inright;
        
//         int i=0,j=0;
//         for(i=0;i<inorder.size();++i){
//             if(inorder[i]!=rootval){
//                 inleft.push_back(inorder[i]);
//                 preleft.push_back(preorder[++j]);
//             }
//             else{
//                 break;
//             }
//         }
//         for(i=i+1;i<inorder.size();++i){
//             inright.push_back(inorder[i]);
//             preright.push_back(preorder[++j]);
//         }
        
//         vector<int>().swap(preorder); //释放preorder的空间
//         vector<int>().swap(inorder);
        
//         root->left=buildTree(preleft,inleft);
//         root->right=buildTree(preright,inright);
        
//         return root;
//     }
// };
    


// 代码二 递归 O(n)  O(logn)
class Solution {   
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(begin(preorder),end(preorder),begin(inorder),end(inorder));
    }
    
    TreeNode* buildTree(vector<int>::iterator pre_first, vector<int>::iterator pre_last, vector<int>::iterator in_first, vector<int>::iterator in_last){
        if(pre_first==pre_last||in_first==in_last){
            return nullptr;
        }
        
        auto root=new TreeNode(*pre_first);
        auto in_rootpos=find(in_first,in_last,*pre_first);
        auto left_size=distance(in_first,in_rootpos);
        
        root->left=buildTree(next(pre_first),next(pre_first,left_size+1),in_first,next(in_first,left_size));
        root->right=buildTree(next(pre_first,left_size+1),pre_last,next(in_first,left_size+1),in_last);
        
        return root;
    }

};