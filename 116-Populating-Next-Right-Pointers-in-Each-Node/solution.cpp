/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==nullptr) return;
        
        deque<TreeLinkNode*> deque_treelinknode;
        
        deque_treelinknode.push_back(root);
        
        int level_size=1;
        vector<TreeLinkNode*> level;
        
        while(deque_treelinknode.size()){
            TreeLinkNode* node=deque_treelinknode.front();
            deque_treelinknode.pop_front();
            
            level.push_back(node);
            
            if(node->left!=nullptr) deque_treelinknode.push_back(node->left);
            
            if(node->right!=nullptr) deque_treelinknode.push_back(node->right);
            
            if(level.size()>=level_size){
                for(int i=0;i<level.size()-1;++i){
                    level[i]->next=level[i+1];
                }
                level[level.size()-1]=nullptr;
                
                level.clear();
                level_size=deque_treelinknode.size();
            }
        }
    }
};