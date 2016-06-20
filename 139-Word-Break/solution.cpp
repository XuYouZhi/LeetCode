// 代码一  动态规划法  状态f(i)表示s[0,i]是否可以分词   f(i)=anyt_of(f(j)&&s[j+1,i] in dict), 0<=j<i
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool>  f(s.size()+1,false);
        f[0]=true;
        for(int i=1;i<=s.size();++i){
            for(int j=0;j<i;++j){
                if(f[j]&&wordDict.find(s.substr(j,i-j))!=wordDict.end()){
                    f[i]=true;
                    break;
                }
            }
        }
        
        return f[s.size()];
    }
};