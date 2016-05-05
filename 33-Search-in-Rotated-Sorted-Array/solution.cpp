// 二分查找 O(logn) O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first=0,last=nums.size();
        
        while(first!=last){
            int mid=first+(last-first)/2;
            
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[first]<nums[mid]){
                if(nums[first]<=target&&nums[mid]>target){
                    last=mid;
                }
                else{
                    first=mid+1;
                }
            }
            else{
                if(nums[mid]<target&&nums[last-1]>=target){
                    first=mid+1;
                }
                else{
                    last=mid;
                }
            }
            
        }
        
        return -1;
    }
};