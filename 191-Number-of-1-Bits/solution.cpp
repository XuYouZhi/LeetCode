class Solution {
public:
    // //方法一 O(T) T为n的二进制位数
    // int hammingWeight(uint32_t n) {
    //     int count=0;
    //     uint32_t flag=1;
    //     while(flag)
    //     {
    //         if(n&flag)
    //         {
    //             ++count;
    //         }
            
    //         flag=flag<<1;
    //     }
        
    //     return count;
    // }
    
    // 方法二 O(M) M为1的个数
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n)
        {
            ++count;
            n=n&(n-1);
        }
    
        return count;
    }
};