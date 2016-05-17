// 代码一 迭代实现 O(2^n)  O(1)
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.reserve(1<<n);
        result.push_back(0);
        
        for(int i=0;i<n;++i){
            const int highest_bit=1<<i;
            for(int j=result.size()-1;j>=0;--j){ //反着遍历才能对称  参考链接：https://zh.wikipedia.org/wiki/%E6%A0%BC%E9%9B%B7%E7%A0%81
                result.push_back(highest_bit|result[j]);
            }
        }
        return result;
    }
};