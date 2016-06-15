// // 代码一 深搜 回溯  长度为n的字符串有n-1个地方可以砍断，每个地方可断可不断，因此复杂度为O(2^n)   O(n)
// class Solution {
// public:
//     vector<vector<string>> partition(string s) {
//           vector<vector<string>> result;
//           vector<string> path;
//           dfs(s,path,result,0,1);
//           return result;
//     }
    
// private:
//     void dfs(string& s, vector<string>& path, vector<vector<string>>& result, int prev, int start){
//         if(start==s.size()){
//             if(isPalindrome(s,prev,start-1)){
//                 path.push_back(s.substr(prev,start-prev));
//                 result.push_back(path);
//                 path.pop_back();
//             }
//             return;
//         }
        
//         //不断开
//         dfs(s,path,result,prev,start+1);
//         //断开
//         if(isPalindrome(s,prev,start-1)){
//             path.push_back(s.substr(prev,start-prev));
//             dfs(s,path,result,start,start+1);
//             path.pop_back();
//         }
//     }
    
//     bool isPalindrome(const string &s, int start, int end){
//         while(start<end&&s[start]==s[end]){
//             ++start;
//             --end;
//         }
//         return start>=end;
//     }
// };



// // 代码二  另一种写法，更加简洁  O(2^n)   O(n)
// class Solution {
// public:
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> result;
//         vector<string> path;
//         dfs(s,path,result,0);
//         return result;
//     }
    
//     //搜索以s[start]开头的partition方案
//     void dfs(string& s, vector<string>& path, vector<vector<string>>& result, int start){
//         if(start==s.size()){
//             result.push_back(path);
//             return;
//         }
        
//         for(int i=start;i<s.size();++i){
//             if(isPalindrome(s,start,i)){ //从i位置砍一刀
//                 path.push_back(s.substr(start,i-start+1));
//                 dfs(s,path,result,i+1);
//                 path.pop_back();
//             }
//         }
//     }
    
//     bool isPalindrome(const string &s, int start, int end){
//         while(start<end&&s[start]==s[end]){
//             ++start;
//             --end;
//         }
//         return start>=end;
//     }
// };


// 代码三  动态规划法
class Solution {
public:
    vector<vector<string>> partition(string s) {
        const int n=s.size();
        bool p[n][n]; //s[i,j]是否回文
        fill_n(&p[0][0],n*n,false);
        for(int i=n-1;i>=0;--i){
            for(int j=i;j<n;++j){
                p[i][j]=s[i]==s[j]&&((j-i<2)||p[i+1][j-1]);
            }
        }
        
        vector<vector<string>> sub_palins[n];
        
        for(int i=n-1;i>=0;--i){
            for(int j=i;j<n;++j){
                if(p[i][j]){
                    const string palindrome=s.substr(i,j-i+1);
                    if(j+1<n){
                        for(auto v:sub_palins[j+1]){
                            v.insert(v.begin(),palindrome);
                            sub_palins[i].push_back(v);
                        }
                    }
                    else{
                        sub_palins[i].push_back(vector<string>{palindrome});
                    }
                }
            }
        }
        
        return sub_palins[0];
    }
};