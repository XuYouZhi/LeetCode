// // 方法一 O(n)  O(n)
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n<=2) return n;
        
//         int f[n+1];
//         f[1]=1;f[2]=2;
//         for(int i=3;i<=n;++i){
//             f[i]=f[i-1]+f[i-2];
//         }
        
//         return f[n];
//     }
// };


// 方法二 O(n) O(1)
class Solution {
public:
    int climbStairs(int n) {
        int prev=1; // 相当于f[i-2] 
        int cur=1; // 相当于f[i-1]  
        
        for(int i=2;i<=n;++i){
            int tmp=cur;
            cur+=prev;
            prev=tmp;
        }
        
        return cur;
    }
};