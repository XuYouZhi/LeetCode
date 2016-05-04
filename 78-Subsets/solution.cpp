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

// 方法二 迭代 增量构造 STL版
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result(1);
        
        sort(nums.begin(),nums.end());
        
        for(auto elem:nums){
            result.reserve(result.size()*2);
            auto half=result.begin()+result.size();
            copy(result.begin(),half,back_inserter(result));
            for_each(half,result.end(),[&elem](decltype(result[0]) &e){e.push_back(elem);});
        }
        
        return result;
    }
};

