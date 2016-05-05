class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n=nums.size();
        
        if(n==0){
            return 0;
        }
        
        int pos=0;
        int count=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[++pos]=nums[i+1];
                count=0;
            }
            else{
                if(count<1){
                    nums[++pos]=nums[i+1];
                    ++count;
                }
            }
        }
        
        return pos+1;
    }
};