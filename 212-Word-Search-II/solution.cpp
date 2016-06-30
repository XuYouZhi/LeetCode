// 代码一 回溯
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        for(int i=0;i<words.size();++i){
            if(exist(board,words[i])){
                result.push_back(words[i]);
            }
        }
        
        sort(result.begin(),result.end()); // ["a"]  ["a","a"]的情况
        result.erase(unique(result.begin(),result.end()),result.end());
        
        return result;
    }
    
    bool exist(vector<vector<char>>& board, string word){
        const int m=board.size();
        if(m==0) return false;
        const int n=board[0].size();
        
        if(word.size()<1) return false;
        
        vector<vector<bool>> used(m,vector<bool>(n,false));
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]==word[0]){
                    if(exist(board,word,m,n,i,j,0,used)) return true;
                }
            }
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, const string& word, int m, int n, int row, int col, int len, vector<vector<bool>>& used){
        if(len==word.length()){
            return true;
        }
        
        if(row<0||row>m-1||col<0||col>n-1) return false;
        
        if(board[row][col]==word[len]&&used[row][col]==false){
            used[row][col]=true;
            if(exist(board,word,m,n,row+1,col,len+1,used)) return true;
            if(exist(board,word,m,n,row,col+1,len+1,used)) return true;
            if(exist(board,word,m,n,row-1,col,len+1,used)) return true;
            if(exist(board,word,m,n,row,col-1,len+1,used)) return true;
            used[row][col]=false;
        }
        else{
            return false;
        }
        
        return false;
    }
};