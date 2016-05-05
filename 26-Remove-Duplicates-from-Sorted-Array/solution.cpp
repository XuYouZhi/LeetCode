class Solution {
public:
    // // 没注意到Sorted Array的前提
    // int removeDuplicates(vector<int>& nums) {
    //     const int n=nums.size();
    //     if(n==0){
    //         return 0;
    //     }
        
    //     int left_idx,right_idx,cur_idx;
    //     left_idx=0;right_idx=n-1;
    //     while(left_idx<right_idx){
    //         cur_idx=left_idx+1;
    //         while(cur_idx<right_idx){
    //             while(nums[right_idx]==nums[left_idx]&&cur_idx<right_idx){
    //                 --right_idx;
    //             }
    //             while(nums[cur_idx]!=nums[left_idx]&&cur_idx<right_idx){
    //                 ++cur_idx;
    //             }
                
    //             if(cur_idx!=right_idx){
    //                 int temp=nums[right_idx];
    //                 nums[right_idx]=nums[cur_idx];
    //                 nums[cur_idx]=temp;
    //                 ++cur_idx;
    //                 --right_idx;
    //             }
    //         }
    //         ++left_idx;
    //     }
        
    //     return left_idx+1;
    // }
    
    int removeDuplicates(vector<int>& nums) {
        const int n=nums.size();
        
        if(n==0){
            return 0;
        }
        
        int pos=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[++pos]=nums[i+1];
            }
        }
        
        return pos+1;
    }
};