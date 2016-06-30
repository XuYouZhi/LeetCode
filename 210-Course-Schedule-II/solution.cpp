class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses,0);
        vector<int> result;
        
        for(auto a:prerequisites){
            graph[a.second].push_back(a.first);
            ++in[a.first];
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;++i){
            if(in[i]==0) {
                q.push(i);
                result.push_back(i);
            }
        }
        
        while(!q.empty()){
            int t=q.front();
            q.pop();
            
            for(auto a:graph[t]){
                --in[a];
                if(in[a]==0) {
                    q.push(a);
                    result.push_back(a);
                }
            }
        }
        
        for(int i=0;i<numCourses;++i){
            if(in[i]!=0) return vector<int>();
        }
        
        return result;
    }
};