class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m=board.size();
        if(m<1) return false;
        const int n=board[0].size();
        
        if(word.size()<1) return false;
        
        vector<vector<bool>> used(m,vector<bool>(n,false));
        
        int i,j;
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(board[i][j]==word[0]){
                    if(exist(board,word,m,n,i,j,0,used)) return true;
                }
            }
        }
        
        return false;
    }
    
    bool exist(const vector<vector<char>>& board, const string& word, int m, int n, int row, int col, int len, vector<vector<bool>>& used){
        if(len==word.length()){
            return true;
        }
        
        if(row<0||row>m-1||col<0||col>n-1) return false;
        
        if(board[row][col]==word[len]&&used[row][col]==false){
            ++len;
            used[row][col]=true;
            if(exist(board,word,m,n,row+1,col,len,used)) return true;
            if(exist(board,word,m,n,row,col+1,len,used)) return true;
            if(exist(board,word,m,n,row-1,col,len,used)) return true;
            if(exist(board,word,m,n,row,col-1,len,used)) return true;
            used[row][col]=false;
        }
        else{
            return false;
        }

        return false;
    }
};