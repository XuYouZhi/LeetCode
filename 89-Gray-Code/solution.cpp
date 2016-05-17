// // 代码一 迭代实现 O(2^n)  O(1)
// class Solution {
// public:
//     vector<int> grayCode(int n) {
//         vector<int> result;
//         result.reserve(1<<n);
//         result.push_back(0);
        
//         for(int i=0;i<n;++i){
//             const int highest_bit=1<<i;
//             for(int j=result.size()-1;j>=0;--j){ //反着遍历才能对称  参考链接：https://zh.wikipedia.org/wiki/%E6%A0%BC%E9%9B%B7%E7%A0%81
//                 result.push_back(highest_bit|result[j]);
//             }
//         }
//         return result;
//     }
// };


// 代码二 数学实现  利用数学公式 0~2^n-1的所有整数转为格雷码（二进制码->格雷码）
// O(2^n) O(1)
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        const size_t size=1<<n;
        result.reserve(size);
        for(size_t i=0;i<size;++i){
            result.push_back(binary_to_gray(i));
        }
        return result;
    }
    
private:
    static unsigned int binary_to_gray(unsigned int n){
        return n^(n>>1);
    }
    
};