// // 代码一 记录没一位上出现1的次数  如果count[i]出现1的次数是3的整数倍，则忽略  O(n) O(1)
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         const int W=sizeof(int)*8;
//         int count[W];
//         fill_n(&count[0],W,0);
//         for(int i=0;i<nums.size();++i){
//             for(int j=0;j<W;++j){
//                 count[j]+=(nums[i]>>j)&1;
//                 count[j]%=3;
//             }
//         }
        
//         int result=0;
//         for(int i=0;i<W;++i){
//             result+=(count[i]<<i);
//         }
//         return result;
//     }
// };



// 代码二  二进制模拟三进制
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0, two=0, three=0;
        for(auto i:nums){
            two|=(one&i);
            one^=i;
            three=~(one&two);
            one&=three;
            two&=three;
        }
        
        return one;
    }
};

