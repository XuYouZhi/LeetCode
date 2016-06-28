class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int n=nums.size();
        for(int i=0;i<n;++i){
            if((i-1<0||nums[i]>nums[i-1])&&(i+1>=n||nums[i]>nums[i+1])){
                return i;
            }
        }
        
        return -1;
    }
};