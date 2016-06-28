// 动态规划
class Solution {
public:
    int rob(vector<int>& nums) {
        int result=0;
        const int n=nums.size();
        
        if(n==0) return result;
        else if(n==1){
            result=nums[0];
            return result;
        }
        else if(n==2){
            result=max(nums[0],nums[1]);
            return result;
        }
        
        vector<int> f(n,0);
        f[0]=nums[0];
        f[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n;++i){
            f[i]=max(f[i-2]+nums[i],f[i-1]);
        }
        
        return f[n-1];
    }
};