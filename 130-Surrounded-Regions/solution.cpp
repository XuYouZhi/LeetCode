// 代码一 测试用例 ["XXXX","XOOX","XXOX","XOXX"]
struct Position{
    int x;
    int y;
    Position(){x=-1;y=-1;}
    Position(int x,int y){
        this->x=x;
        this->y=y;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j]=='O'){
                    solve(board,i,j);
                }
            }
        }
        
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j]=='+'){
                    board[i][j]='O';
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board, int row, int col){
        const int max_row=board.size();
        const int max_col=board[0].size();
        queue<Position> cur;
        vector<Position> region;
                
        auto position_extend=[&](const Position& p){
            bool flag=false;
            
            if(p.x==0||p.y==0||p.x==max_row-1||p.y==max_col-1) flag=true;
            Position offsets[4]={Position(-1,0),Position(1,0),Position(0,-1),Position(0,1)};
            for(int i=0;i<4;++i){
                int x=p.x+offsets[i].x;
                int y=p.y+offsets[i].y;
                if(x<0||x>=max_row||y<0||y>=max_col) continue;
                if(board[x][y]=='O'){
                    cur.push(Position(x,y));
                    board[x][y]='+';
                    if(x==0||y==0||x==max_row-1||y==max_col-1) flag=true;
                }
            }
            
            return flag;
        };
        

        cur.push(Position(row,col));
        board[row][col]='+';
        bool surrounded=true; 
        while(!cur.empty()){
            Position p=cur.front();
            cur.pop();
            
            region.push_back(p);
            
            if(position_extend(p)){
                surrounded=false;
            }
        }
        
        if(surrounded){
            for(const auto& r:region){
                board[r.x][r.y]='X';
            }
        }
    }
};