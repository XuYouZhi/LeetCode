// // 代码一 动态规划  O(n^2)  O(n^2)
// // f[i][j]表示 s1[0,i]和s2[0,j]匹配 s3[0,i+j]   转移方程：f[i][j]=(s1[i-1]==s3[i+j-1]&&f[i-1][j])||(s2[j-1]==s3[i+j-1]&&f[i][j-1])
// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         if(s3.length()!=s1.length()+s2.length()) return false;
        
//         vector<vector<bool>> f=vector<vector<bool>>(s1.length()+1,vector<bool>(s2.length()+1,true));
        
//         for(int i=1;i<=s1.length();++i){
//             f[i][0]=(s1[i-1]==s3[i-1])&&f[i-1][0];
//         }
        
//         for(int j=1;j<=s2.length();++j){
//             f[0][j]=(s2[j-1]==s3[j-1])&&f[0][j-1];
//         }
        
//         for(int i=1;i<=s1.length();++i){
//             for(int j=1;j<=s2.length();++j){
//                 f[i][j]=(s1[i-1]==s3[i+j-1]&&f[i-1][j])||(s2[j-1]==s3[i+j-1]&&f[i][j-1]);
//             }
//         }
        
//         return f[s1.length()][s2.length()];
//     }
// };



// 代码二 动态规划+滚动数组 O(n^2) O(n)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length()!=s1.length()+s2.length()) return false;
        
        if(s1.length()<s2.length()) return isInterleave(s2,s1,s3);
        
        vector<bool> f(s2.length()+1,true);
        
        for(int j=1;j<=s2.length();++j){
            f[j]=(s2[j-1]==s3[j-1])&&f[j-1];  // f[j]  代表代码一中的f[0][j]
        }
        
        for(int i=1;i<=s1.length();++i){
            f[0]=(s1[i-1]==s3[i-1])&&f[0];   //f[i][0]=(s1[i-1]==s3[i-1])&&f[i-1][0];
            for(int j=1;j<=s2.length();++j){
                f[j]=(s1[i-1]==s3[i+j-1]&&f[j])||(s2[j-1]==s3[i+j-1]&&f[j-1]);
            }
        }
        
        return f[s2.length()];
    }
};