// 方法一  Time Limit Exceeded

typedef pair<int,int> state_t;

//模板特化   用于hash unordered_set<state_t>
namespace std{
    template<>
    struct hash<state_t>{
    public:
        size_t operator()(const state_t &s) const{
            return hash<int>()(s.first) ^ hash<int>()(s.second);
        }
        
    private:
    };
}


class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        const int m=grid.size();
        if(m==0) return 0;
        const int n=grid[0].size();
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        int result=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]=='1'&&visited[i][j]==false){
                    result+=numIslands(grid,visited,i,j);
                }
            }
        }
        
        return result;
    }
    
    int numIslands(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        const int m=grid.size();
        const int n=grid[0].size();
        
        auto state_is_valid=[&](const state_t &s){
            const int x=s.first;
            const int y=s.second;
            if(x<0||x>=m||y<0||y>=n||grid[x][y]!='1'||visited[x][y]==true) return false;
            return true;
        };
        
        auto state_extend=[&](const state_t &s){
            vector<state_t> result;
            const int x=s.first;
            const int y=s.second;
            
            const state_t new_states[4]={{x-1,y},{x+1,y},{x,y-1},{x,y+1}};
            
            for(int k=0;k<4;++k){
                if(state_is_valid(new_states[k])){
                    result.push_back(new_states[k]);
                }
            }
            
            return result;
        };
        
        
        queue<state_t> q;
        q.push(make_pair(x,y));
        
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            if(visited[cur.first][cur.second]==true) continue;
            visited[cur.first][cur.second]=true;
            auto new_states=state_extend(cur);
            for(auto s:new_states) {
                q.push(s);
            }
        }
        
        return 1;
        
    }
};