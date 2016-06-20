/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
// DFS O(n) O(n)
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==nullptr) return nullptr;
        unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copied;
        
        clone(node,copied);
        
        return copied[node];
    }
    
    
private:
    static UndirectedGraphNode* clone(const UndirectedGraphNode *node, unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> &copied){
        if(copied.find(node)!=copied.end()) return copied[node];
        
        UndirectedGraphNode *new_node=new UndirectedGraphNode(node->label);
        copied[node]=new_node;
        for(auto nbr:node->neighbors){
            new_node->neighbors.push_back(clone(nbr,copied));
        }
        
        return new_node;
    }
};