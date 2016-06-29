// // 代码一 Time Limit Exceeded
// class Solution {
// public:
//     int rangeBitwiseAnd(int m, int n) {
//         int result=m;
//         for(int i=m+1;i<=n;++i){
//             result&=i;
//             if(result==0) return 0;
//         }
//         return result;
//     }
// };


// // 代码二 建立一个32位都是1的mask，然后每次向左移一位，比较m和n是否相同，不同再继续左移一位，直至相同，然后把m和mask相与就是最终结果
// class Solution {
// public:
//     int rangeBitwiseAnd(int m, int n) {
//         unsigned int msk=~(0x0);
//         while((m&msk)!=(n&msk)){
//             msk<<=1;
//         }
        
//         return m&msk;
//     }
// };


// 代码三 直接平移m和n，每次向右移一位，直到m和n相等，记录下所有平移的次数i，然后再把m左移i位即为最终结果
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i=0;
        while(m!=n){
            m>>=1;
            n>>=1;
            ++i;
        }
        
        return m<<i;
    }
};