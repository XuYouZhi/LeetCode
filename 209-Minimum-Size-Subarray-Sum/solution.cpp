class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result=INT_MAX;
        const int n=nums.size();
        
        int i=0,j=0;
        int sum=0;
        while(i<n){
            if(sum<s){
                while(sum<s&&j<n){
                    sum+=nums[j];
                    ++j;
                }
            }
            else{
                while(sum-nums[j-1]>=s&&j>=0){
                    sum-=nums[j-1];
                    --j;
                }
            }
            
            cout<<sum<<" "<<i<<" "<<j<<endl;
            
            if(sum>=s&&j-i<result){ //注意不是j-i+1  j已经++过了
                result=j-i;
            }

            sum-=nums[i];
            ++i;
        }
        
        return result==INT_MAX?0:result;
    }
};