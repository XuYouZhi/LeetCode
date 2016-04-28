class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n=nums.size();
        if(n<1) return -1;

        int sum=0;
        int max_sub=INT_MIN;
        for(int i=0;i<n;++i){
            sum+=nums[i];            
            
            if(sum>max_sub){
                max_sub=sum;
            }
            
            if(sum<0){
                sum=0;
            }
        }
        
        return max_sub;
    }
};