/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
// // 代码一 DFS O(n) O(n)
// class Solution {
// public:
//     UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
//         if(node==nullptr) return nullptr;
//         unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copied;
        
//         clone(node,copied);
        
//         return copied[node];
//     }
    
    
// private:
//     static UndirectedGraphNode* clone(const UndirectedGraphNode *node, unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> &copied){
//         if(copied.find(node)!=copied.end()) return copied[node];
        
//         UndirectedGraphNode *new_node=new UndirectedGraphNode(node->label);
//         copied[node]=new_node;
//         for(auto nbr:node->neighbors){
//             new_node->neighbors.push_back(clone(nbr,copied));
//         }
        
//         return new_node;
//     }
// };


// 代码二 BFS O(n)  O(n)
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==nullptr) return nullptr;
        
        unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copied;
        
        queue<const UndirectedGraphNode *> q;
        q.push(node);
        copied[node]=new UndirectedGraphNode(node->label);
        while(!q.empty()){
            const UndirectedGraphNode *cur=q.front();
            q.pop();
            for(auto nbr:cur->neighbors){
                if(copied.find(nbr)!=copied.end()){
                    copied[cur]->neighbors.push_back(copied[nbr]);
                }
                else{
                    UndirectedGraphNode *new_node= new UndirectedGraphNode(nbr->label);
                    copied[nbr]=new_node;
                    copied[cur]->neighbors.push_back(new_node);
                    q.push(nbr);
                }
            }
        }
        
        return copied[node];
    }
};