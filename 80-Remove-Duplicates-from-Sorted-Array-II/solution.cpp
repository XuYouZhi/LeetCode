// // 代码一  O(n) O(1)
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         const int n=nums.size();
        
//         if(n==0){
//             return 0;
//         }
        
//         int pos=0;
//         int count=0;
//         for(int i=0;i<n-1;i++){
//             if(nums[i]!=nums[i+1]){
//                 nums[++pos]=nums[i+1];
//                 count=0;
//             }
//             else{
//                 if(count<1){
//                     nums[++pos]=nums[i+1];
//                     ++count;
//                 }
//             }
//         }
        
//         return pos+1;
//     }
// };


// 代码二 O(n) O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        
        int index=2;
        
        for(int i=2;i<nums.size();++i){
            if(nums[i]!=nums[index-2]){
                nums[index++]=nums[i];
            }
        }
        
        return index;
    }
};