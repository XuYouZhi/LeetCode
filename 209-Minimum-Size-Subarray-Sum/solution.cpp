// // 代码一 双指针 O(n)
// class Solution {
// public:
//     int minSubArrayLen(int s, vector<int>& nums) {
//         int result=INT_MAX;
//         const int n=nums.size();
        
//         int i=0,j=0;
//         int sum=0;
//         while(i<n){
//             if(sum<s){
//                 while(sum<s&&j<n){
//                     sum+=nums[j];
//                     ++j;
//                 }
//             }
//             else{
//                 while(sum-nums[j-1]>=s&&j>=0){
//                     sum-=nums[j-1];
//                     --j;
//                 }
//             }
            
//             cout<<sum<<" "<<i<<" "<<j<<endl;
            
//             if(sum>=s&&j-i<result){ //注意不是j-i+1  [i,j)
//                 result=j-i;
//             }

//             sum-=nums[i];
//             ++i;
//         }
        
//         return result==INT_MAX?0:result;
//     }
// };



// 代码二 
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int len=nums.size();
        int result=len+1;
        
        int sums[len+1]={0};
        for(int i=1;i<len+1;++i){
            sums[i]=sums[i-1]+nums[i-1];
        }
        
        for(int i=0;i<len+1;++i){
            int right=searchRight(i+1,len,sums[i]+s,sums); // left right key sums
            if(right==len+1) break;
            if(right-i<result) result=right-i;
        }
        
        return result==len+1?0:result;
    }
    
    int searchRight(int left, int right, int key, int sums[]){
        while(left<=right){
            int mid=left+(right-left)/2;
            //right=n-1 => while(left <= right) => right=middle-1;  
            //right=n   => while(left <  right) => right=middle; 
            if(sums[mid]>=key) right=mid; // 注意为mid-1   
            else left=mid+1;
        }
        return left;
    }
};