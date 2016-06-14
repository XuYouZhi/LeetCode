// // 代码一 对于每一个‘O’进行扩展，如果扩展到了边界，则保留，否则变为‘X’   测试用例["XOXX","OXOX","XOXO","OXOX"]
// struct Position{
//     int x;
//     int y;
//     Position(){x=-1;y=-1;}
//     Position(int x,int y){
//         this->x=x;
//         this->y=y;
//     }
// };

// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         for(int i=0;i<board.size();++i){
//             for(int j=0;j<board[0].size();++j){
//                 if(board[i][j]=='O'){
//                     solve(board,i,j);
//                 }
//             }
//         }
        
//         for(int i=0;i<board.size();++i){
//             for(int j=0;j<board[0].size();++j){
//                 if(board[i][j]=='+'){
//                     board[i][j]='O';
//                 }
//             }
//         }
//     }
    
//     void solve(vector<vector<char>>& board, int row, int col){
//         const int max_row=board.size();
//         const int max_col=board[0].size();
//         queue<Position> cur;
//         vector<Position> region;
                
//         auto position_extend=[&](const Position& p){
//             bool flag=false;
            
//             if(p.x==0||p.y==0||p.x==max_row-1||p.y==max_col-1) flag=true;
//             Position offsets[4]={Position(-1,0),Position(1,0),Position(0,-1),Position(0,1)};
//             for(int i=0;i<4;++i){
//                 int x=p.x+offsets[i].x;
//                 int y=p.y+offsets[i].y;
//                 if(x<0||x>=max_row||y<0||y>=max_col) continue;
//                 if(board[x][y]=='O'){
//                     cur.push(Position(x,y));
//                     board[x][y]='+';
//                     if(x==0||y==0||x==max_row-1||y==max_col-1) flag=true;
//                 }
//             }
            
//             return flag;
//         };
        

//         cur.push(Position(row,col));
//         board[row][col]='+';
//         bool surrounded=true; 
//         while(!cur.empty()){
//             Position p=cur.front();
//             cur.pop();
            
//             region.push_back(p);
            
//             if(position_extend(p)){
//                 surrounded=false;
//             }
//         }
        
//         if(surrounded){
//             for(const auto& r:region){
//                 board[r.x][r.y]='X';
//             }
//         }
//     }
// };



// 代码二 广搜 从上下左右四个边界往里走，凡是碰到的‘O’都是跟边界接壤的，应该保留   O(n)  O(n)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        
        const int m=board.size();
        const int n=board[0].size();
        
        for(int i=0;i<n;++i){
            bfs(board,0,i); //上边界
            bfs(board,m-1,i); //下边界
        }
        for(int j=1;j<m-1;++j){
            bfs(board,j,0); //左边界
            bfs(board,j,n-1); //右边界
        }
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='+') board[i][j]='O';
            }
        }
    }
    
    
private:
    void bfs(vector<vector<char>> &board, int i, int j){
        typedef pair<int, int> state_t;
        queue<state_t> q;
        
        const int m=board.size();
        const int n=board[0].size();
        
        auto state_is_valid=[&](const state_t &s){
            const int x=s.first;
            const int y=s.second;
            if(x<0||x>=m||y<0||y>=n||board[x][y]!='O') return false;
            return true;
        };
        
        auto state_extend=[&](const state_t &s){
            vector<state_t> result;
            const int x=s.first;
            const int y=s.second;
            
            const state_t new_states[4]={{x-1,y},{x+1,y},{x,y-1},{x,y+1}};
            
            for(int k=0;k<4;++k){
                if(state_is_valid(new_states[k])){
                    board[new_states[k].first][new_states[k].second]='+';
                    result.push_back(new_states[k]);
                }
            }
            
            return result;
        };
        
        state_t start={i,j};
        
        if(state_is_valid(start)){
            board[i][j]='+';
            q.push(start);
        }
        
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            auto new_states=state_extend(cur);
            for(auto s:new_states) q.push(s);
        }
    }
};

