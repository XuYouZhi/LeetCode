// // 方法一  迭代  增量构造  O(2^n)  O(1)
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> result(1);
        
//         sort(nums.begin(),nums.end());
        
//         for(int i=nums.size()-1;i>=0;--i){
//             const int n=result.size();
//             for(int j=0;j<n;++j){
//                 vector<int> tmp=result[j];
//                 tmp.insert(tmp.begin(),nums[i]);
//                 result.push_back(tmp);
//             }
//         }
        
//         return result;
//     }
// };



// // 方法二 迭代 增量构造 STL版
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> result(1);
        
//         sort(nums.begin(),nums.end());
        
//         for(auto elem:nums){
//             result.reserve(result.size()*2);
//             auto half=result.begin()+result.size();
//             copy(result.begin(),half,back_inserter(result));
//             for_each(half,result.end(),[&elem](decltype(result[0]) &e){e.push_back(elem);});
//         }
        
//         return result;
//     }
// };



// 方法二 迭代 二进制法 类似于位向量法  O(2^n) O(1) 
// 前提是几何的元素不超过int位数。 用一个int表示为向量，第i为位为1，则表示选择s[i]，否则不选择
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(nums.begin(),nums.end());
        
        const size_t n=nums.size();
        vector<int> v;
        
        for(size_t i=0;i<1<<n;++i){
            for(size_t j=0;j<n;++j){
                if(i&1<<j) v.push_back(nums[j]);
            }
            result.push_back(v);
            v.clear();
        }
        
        return result;
    }
};
