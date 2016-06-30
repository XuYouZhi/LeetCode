// House Robber I的升级，由于首尾相连，第一户和最后一户不能同时抢，可转化为去掉第一户和去掉最后一户分别抢两次，求最大的问题
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n=nums.size();
        if(n==0) return 0;
        else if(n==1) return nums[0];
        else if(n==2) return max(nums[0],nums[1]);
        
        return max(rob(nums,0,n-2),rob(nums,1,n-1));
    }
    
    int rob(vector<int>& nums, int start, int end){ // [start,end]
        int result=0;
        const int n=end-start+1;
        
        vector<int> f(n,0);
        f[0]=nums[start];
        f[1]=max(nums[start],nums[start+1]);
        
        for(int i=2;i<n;++i){
            f[i]=max(f[i-2]+nums[start+i],f[i-1]);
        }
        
        return f[n-1];
    }
};