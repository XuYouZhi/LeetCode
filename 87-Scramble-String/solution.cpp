// // 代码一 动态规划法 设状态为f[n][i][j]，表示长度为n,起点为s1[i]和起点为s2[j]的两个字符串互为scramble
// // f[n][i][j]=(f[k][i][j]&&f[n-k][i+k][j+k])||(f[k][i][j+n-k]&&f[n-k][i+k][j])
// // O(n^3) O(n^3)
// class Solution {
// public:
//     bool isScramble(string s1, string s2) {
//         const int N=s1.size();
//         if(N!=s2.size()) return false;
        
//         bool f[N+1][N][N];
//         fill_n(&f[0][0][0],(N+1)*N*N,false);
        
//         for(int i=0;i<N;++i){
//             for(int j=0;j<N;++j){
//                 f[1][i][j]=(s1[i]==s2[j]);
//             }
//         }
        
//         for(int n=1;n<=N;++n){
//             for(int i=0;i+n<=N;++i){
//                 for(int j=0;j+n<=N;++j){
//                     for(int k=1;k<n;++k){
//                         if((f[k][i][j]&&f[n-k][i+k][j+k])||(f[k][i][j+n-k]&&f[n-k][i+k][j])){
//                             f[n][i][j]=true;
//                             break;
//                         }
//                     }
//                 }
//             }
//         }
        
//         return f[N][0][0];
//     }
// };


// 代码二  深搜（递归）+剪枝（利用字符串中每个字符出现的次数相等来剪枝）  O(n^6)  O(1)
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        return isScramble(s1.begin(),s1.end(),s2.begin());
    }
    
    typedef string::const_iterator Iterator;
    
    bool isScramble(Iterator first1, Iterator last1, Iterator first2){
        auto length=distance(first1,last1);
        auto last2=next(first2,length);
        if(length==1) return *first1==*first2;
        
        //剪枝 提前返回
        int A[26];
        fill(A,A+26,0);
        for(int i=0;i<length;++i) A[*(first1+i)-'a']++;
        for(int i=0;i<length;++i) A[*(first2+i)-'a']--;
        for(int i=0;i<26;++i) if(A[i]!=0) return false;
        
        for(int i=1;i<length;++i){
            if((isScramble(first1,first1+i,first2)&&isScramble(first1+i,last1,first2+i))||(isScramble(first1,first1+i,last2-i)&&isScramble(first1+i,last1,first2))){
                return true;
            }
        }
        
        return false;
    }
};


// // 代码三 备忘录 递归+map做cache  Time Limit Exceeded 
// class Solution {
// public:
//     bool isScramble(string s1, string s2) {
//         if(s1.size()!=s2.size()) return false;
        
//         cache.clear();
//         return isScramble(s1.begin(),s1.end(),s2.begin());
//     }
    
//     typedef string::const_iterator Iterator;
//     map<tuple<Iterator,Iterator,Iterator>,bool> cache;
    
//     bool isScramble(Iterator first1, Iterator last1, Iterator first2){
//         auto length=distance(first1,last1);
//         auto last2=next(first2,length);
        
//         if(length==1) return *first1==*first2;
        
//         for(int i=1;i<length;++i){
//             if((getOrUpdate(first1,first1+i,first2)&&getOrUpdate(first1+i,last1,first2+i))||(getOrUpdate(first1,first1+i,last2-i)&&getOrUpdate(first1+i,last1,first2))){
//                 return true;
//             }
//         }
        
//         return false;
//     }
    
    
//     bool getOrUpdate(Iterator first1, Iterator last1, Iterator first2){
//         auto key=make_tuple(first1,last1,first2);
//         auto pos=cache.find(key);
        
//         return (pos!=cache.end())?pos->second:(cache[key]=isScramble(first1,last1,first2));
//     }
// };
