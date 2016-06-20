// O(n^2)  O(n^2)
class Solution {
public:
    // 动规
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<vector<bool> > prev(s.length()+1,vector<bool>(s.length())); 
        
        vector<bool> f(s.size()+1);
        f[0]=true;
        for(int i=1;i<=s.size();++i){
            for(int j=0;j<i;++j){
                if(f[j]&&wordDict.find(s.substr(j,i-j))!=wordDict.end()){
                    f[i]=true;
                    prev[i][j]=true;//prev[i][j]为true表示s[j,i)是个合法单词，可以从j切开
                }
            }
        }
        
        
        vector<string> result;
        vector<string> path;
        gen_path(s,prev,s.length(),path,result);
        return result;
    }
    
    
private:
    // DFS 生成路径
    void gen_path(const string &s, const vector<vector<bool> > &prev, int cur, vector<string>& path, vector<string>& result){
        if(cur==0){
            string tmp;
            for(auto iter=path.crbegin();iter!=path.crend();++iter){
                tmp+=*iter+" ";
            }
            tmp.erase(tmp.end()-1);
            result.push_back(tmp);
        }
        
        for(size_t i=0;i<cur;++i){
            if(prev[cur][i]){
                path.push_back(s.substr(i,cur-i));
                gen_path(s,prev,i,path,result);
                path.pop_back();
            }
        }
    }
};