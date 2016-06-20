// 代码一  动态规划法 O(n^2) O(n)  状态f(i)表示s[0,i]是否可以分词   f(i)=anyt_of(f(j)&&s[j+1,i] in dict), 0<=j<i
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



// // 代码二 深搜  超时  O(2^n)  O(n)
// class Solution {
// public:
//     bool wordBreak(string s, unordered_set<string>& wordDict) {
//         return dfs(s,wordDict,0,0);
//     }
    
// private:
//     static bool dfs(const string &s, unordered_set<string> &wordDict, size_t start, size_t cur){
//         if(cur==s.size()){
//             return wordDict.find(s.substr(start, cur-start+1))!=wordDict.end();
//         }
        
//         if(dfs(s,wordDict,start,cur+1)) return true; //不断
//         if(wordDict.find(s.substr(start,cur-start+1))!=wordDict.end()){
//             if(dfs(s,wordDict,cur+1,cur+1)) return true; // 断
//         }
        
//         return false;
//     }
// };