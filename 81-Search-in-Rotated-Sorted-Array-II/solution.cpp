// 允许重复元素的话，如果nums[first]<=nums[mid] 时并不能保证  [first,mid] 为递增了，例如[1,3,1,1,1]   [1,1,1,3,1]
// 所以将其拆分为 nums[mid]>nums[first] (first~mid一定递增 )和nums[mid]==nums[first](确定不了，first++)两个条件。
// O(n) O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int first=0, last=nums.size();
        
        while(first!=last){
            int mid=first+(last-first)/2;
            
            if(nums[mid]==target){
                return true;
            }
            else if(nums[first]<nums[mid]){ 
                if(nums[first]<=target&&nums[mid]>target){
                    last=mid;
                }
                else{
                    first=mid+1;
                }
            }
            else if(nums[first]>nums[mid]){
                if(nums[mid]<target&&nums[last-1]>=target){
                    first=mid+1;
                }
                else{
                    last=mid;
                }
            }
            else{ // nums[first]==nums[mid]
                ++first;
            }
        }
        
        return false;
    }
};