// // 代码一 只需要把要翻转的数从右向左一位位的取出来，然后加到新生成的数的最低位即可
// class Solution {
// public:
//     uint32_t reverseBits(uint32_t n) {
//         uint32_t res=0;
        
//         // //方法一
//         // for(int i=0;i<32;++i){
//         //     if(n&1==1){
//         //         res=(res<<1)+1;
//         //     }
//         //     else{
//         //         res<<=1;
//         //     }
//         //     n>>=1;
//         // }
        
//         // 方法二
//         for(int i=0;i<32;++i){
//             res|=((n>>i)&1)<<(31-i);
//         }
        
//         return res;
//     }
// };



// 代码二  以4位单位进行反转
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        char tb[16] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
        uint32_t res;
        uint32_t msk=0xf;
        for(int i=0;i<8;++i){
            res<<=4;
            uint32_t cur=n&msk;
            res|=tb[cur];
            n>>=4;
        }
        return res;
    }
};