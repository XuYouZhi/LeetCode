// // 代码一 回溯  Word Search I基础上对每个word进行判断   Time Limit Exceeded
// class Solution {
// public:
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         vector<string> result;
//         for(int i=0;i<words.size();++i){
//             if(exist(board,words[i])){
//                 result.push_back(words[i]);
//             }
//         }
        
//         sort(result.begin(),result.end()); // ["a"]  ["a","a"]的情况
//         result.erase(unique(result.begin(),result.end()),result.end());
        
//         return result;
//     }
    
//     bool exist(vector<vector<char>>& board, string word){
//         const int m=board.size();
//         if(m==0) return false;
//         const int n=board[0].size();
        
//         if(word.size()<1) return false;
        
//         vector<vector<bool>> used(m,vector<bool>(n,false));
        
//         for(int i=0;i<m;++i){
//             for(int j=0;j<n;++j){
//                 if(board[i][j]==word[0]){
//                     if(exist(board,word,m,n,i,j,0,used)) return true;
//                 }
//             }
//         }
        
//         return false;
//     }
    
//     bool exist(vector<vector<char>>& board, const string& word, int m, int n, int row, int col, int len, vector<vector<bool>>& used){
//         if(len==word.length()){
//             return true;
//         }
        
//         if(row<0||row>m-1||col<0||col>n-1) return false;
        
//         if(board[row][col]==word[len]&&used[row][col]==false){
//             used[row][col]=true;
//             if(exist(board,word,m,n,row+1,col,len+1,used)) return true;
//             if(exist(board,word,m,n,row,col+1,len+1,used)) return true;
//             if(exist(board,word,m,n,row-1,col,len+1,used)) return true;
//             if(exist(board,word,m,n,row,col-1,len+1,used)) return true;
//             used[row][col]=false;
//         }
//         else{
//             return false;
//         }
        
//         return false;
//     }
// };



// 代码二  回溯+Trie
class Solution {
public:
    class TrieNode{
    public:
        TrieNode* child[26];
        bool isWord;
        
        TrieNode(){
            isWord=false;
            for(auto &c:child) c=nullptr;
        }
    };
    
    
    class Trie{
    public:
        Trie(){
            root=new TrieNode();
        }
        
        void insert(string word){
            TrieNode *p=root;
            for(auto c:word){
                int i=c-'a';
                if(!p->child[i]) p->child[i]=new TrieNode();
                p=p->child[i];
            }
            p->isWord=true;
        }
        
        
        bool search(string word) const{
            TrieNode *p=root;
            for(auto c:word){
                int i=c-'a';
                if(!p->child[i]) return false;
                p=p->child[i];
            }
            return p->isWord;
        }
        
        bool startsWith(string prefix) const{
            TrieNode *p=root;
            for(auto c:prefix){
                int i=c-'a';
                if(!p->child[i]) return false;
                p=p->child[i];
            }
            return true;
        }
        
    private:
        TrieNode *root;
    };
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        
        const int m=board.size();
        if(m==0) return result;
        const int n=board[0].size();
        
        vector<vector<bool>> used(m,vector<bool>(n,false));
        
        Trie *trie=new Trie();
        for(auto w:words){
            trie->insert(w);
        }
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                dfs(board,trie,used,"",i,j,result);
            }
        }

        sort(result.begin(),result.end()); // ["a"]  ["a","a"]的情况
        result.erase(unique(result.begin(),result.end()),result.end());

        return result;
    }
    
    void dfs(const vector<vector<char>>& board, const Trie* trie, vector<vector<bool>>& used, string str, int x, int y, vector<string>& result){
        if(x<0||x>board.size()-1||y<0||y>board[0].size()-1) return;
        
        if(used[x][y]) return;
        
        str+=board[x][y];
        if(!trie->startsWith(str)) return;
        
        if(trie->search(str)) result.push_back(str);
        
        used[x][y]=true;
        dfs(board, trie, used, str, x-1, y, result);
        dfs(board, trie, used, str, x+1, y, result);
        dfs(board, trie, used, str, x, y-1, result);
        dfs(board, trie, used, str, x, y+1, result);
        used[x][y]=false;
    }
};


