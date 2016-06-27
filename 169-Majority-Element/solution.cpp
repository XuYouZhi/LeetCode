// O(n) O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        int major=nums[0];
        for(int i=1;i<nums.size();++i){
            if(major==nums[i]){
                ++cnt;
            }
            else if(cnt==0){
                major=nums[i];
                cnt=1;
            }
            else{
                --cnt;
            }
        }
        
        return major;
    }
};