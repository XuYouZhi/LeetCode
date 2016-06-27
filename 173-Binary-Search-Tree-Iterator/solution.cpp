/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
思路：这道题等价于写一个二叉树中序遍历的迭代器。需要内置一个栈，一开始先存储到最左叶子节点的路径。在遍历的过程中，只要当前节点存在右孩子，   则进入右孩子，存除从此处开始到当前子树里最左叶子节点的路径。
*/
class BSTIterator {
private:
    stack<TreeNode*> stk;
    
public:
    BSTIterator(TreeNode *root) {
        while(root!=nullptr){
            stk.push(root);
            root=root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node=stk.top();
        int result=node->val;
        stk.pop();
        
        if(node->right!=nullptr){
            node=node->right;
            while(node!=nullptr){
                stk.push(node);
                node=node->left;
            }
        }
        
        return result;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */