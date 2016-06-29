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


// 代码二 建立一个32位都是1的mask，然后每次向左移一位，比较m和n是否相同，不同再继续左移一位，直至相同，然后把m和mask相与就是最终结果
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        unsigned int msk=~(0x0);
        while((m&msk)!=(n&msk)){
            msk<<=1;
        }
        
        return m&msk;
    }
};