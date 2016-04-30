// // 方法一 动态规划法 时间复杂度O(n^2)  空间O(n^2)   m(i,j)表示区间[i,j]是否为回文串
// //        : true                    i=j  
// // m(i,j) : s[i]=s[j]               j=i+1
// //        : m(i+1,j-1)&&s[i]=s[j]   j>i
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         const int n=s.size();
//         if(n==0){
//             return s;
//         }
        
//         bool m[n][n];
//         memset(m,0,sizeof(bool)*n*n);
        
//         size_t max_len=1,start=0;
//         for(size_t i=0;i<n;i++){
//             m[i][i]=true;
//             for(size_t j=0;j<i;j++){ // 上三角类似，从左到右，从上到下填充
//                 m[j][i]=(s[i]==s[j])&&(i-j<2||m[j+1][i-1]);  
//                 if(m[j][i]&&max_len<i-j+1){
//                     max_len=i-j+1;
//                     start=j;
//                 }
//             }
//         }
        
//         return s.substr(start,max_len);
//     }
// };


//方法二 Manacher's Algorithm  O(n) O(n)  https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.05.md
class Solution {
public:
    string longestPalindrome(string s) {
        string T=preProcess(s);
        const int n=T.length();
        int P[n];
        int C=0,R=0;
        
        for(int i=1;i<n-1;++i){
            int i_mirror=2*C-i;// C-(i-C)
            
            P[i]=(R>i)?min(R-i,P[i_mirror]):0;
            
            while(T[i+1+P[i]]==T[i-1-P[i]]) P[i]++;
            
            if(i+P[i]>R){
                C=i;
                R=i+P[i];
            }
        }
        
        // Find the maximum element in P
        int max_len=0;
        int center_index=0;
        for(int i=1;i<n-1;++i){
            if(P[i]>max_len){
                max_len=P[i];
                center_index=i;
            }
        }
        
        
        return s.substr((center_index-1-max_len)/2,max_len);
    }
    
    
    // Transform S into T.
    // For example, S = "abba", T = "^#a#b#b#a#$".
    // ^ and $ signs are sentinels appended to each end to avoid bounds checking
    string preProcess(const string& s){
        int n=s.length();
        
        if(n==0) return "^$";
        
        string ret="^";
        for(int i=0;i<n;++i){
            ret+="#"+s.substr(i,1);
        }
        ret+="#$";
        
        return ret;
    }
};
