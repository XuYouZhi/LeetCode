class Solution {
// //方法一  每次移动一个，太繁琐，O(m+n)
// public:
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int median_pos=(nums1.size()+nums2.size()+1)/2-1;

    //     bool even=false;
    //     if((nums1.size()+nums2.size())%2==0){
    //         even=true;    
    //     }
        
    //     if(median_pos<0){
    //         return 0.0;
    //     }
        
    //     if(nums1.size()==0){
    //         if(even){
    //             return (nums2[median_pos]+nums2[median_pos+1])/2.0;
    //         }
    //         return nums2[median_pos];
    //     }
        
    //     if(nums2.size()==0){
    //         if(even){
    //             return (nums1[median_pos]+nums1[median_pos+1])/2.0;
    //         }
    //         return nums1[median_pos];
    //     }
        
    //     int count=0;
    //     double result=0.0;
        
    //     for(int i=0;i<nums1.size();){
    //         for(int j=0;j<nums2.size();){
    //             if(nums1[i]>nums2[j]){
    //                 result=nums2[j];
    //                 ++j;
    //             }
    //             else{
    //                 result=nums1[i];
    //                 ++i;    
    //             }
                
    //             ++count;
                
    //             if(i>=nums1.size()&&count<=median_pos){
    //                 if(even){
    //                     return (nums2[median_pos-nums1.size()]+nums2[median_pos+1-nums1.size()])/2.0;
    //                 }
    //                 return nums2[median_pos-nums1.size()];
    //             }
                
    //             if(j>=nums2.size()&&count<=median_pos){
    //                 if(even){
    //                     return (nums1[median_pos-nums2.size()]+nums1[median_pos+1-nums2.size()])/2.0;
    //                 }
    //                 return nums1[median_pos-nums2.size()];
    //             }
                
                
    //             if(count>median_pos){
    //                 if(even){
    //                     if(i>=nums1.size()){
    //                         return (result+nums2[j])/2.0;
    //                     }
    //                     if(j>=nums2.size()){
    //                         return (result+nums1[i])/2.0;
    //                     }
                        
    //                     if(nums1[i]>nums2[j]){
    //                         return (result+nums2[j])/2.0;
    //                     }
    //                     else
    //                     {
    //                         return (result+nums1[i])/2.0;
    //                     }
    //                 }
    //                 return result;
    //             }
    //         }
    //     }
    // }


// 方法二 每次去除k/2个元素, O(log(m+n))
public:   
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m=nums1.size();
        const int n=nums2.size();
        int total=m+n;
        if(total & 0x01){ //odd
            return __findKth(nums1.begin(),m,nums2.begin(),n,total/2+1);
        }
        else{
            return (__findKth(nums1.begin(),m,nums2.begin(),n,total/2)+__findKth(nums1.begin(),m,nums2.begin(),n,total/2+1))/2.0;
        }
        
    }
    
    
private:
    int __findKth(vector<int>::const_iterator nums1, int m, vector<int>::const_iterator nums2, int n, int k){
        if(m>n) return __findKth(nums2,n,nums1,m,k);// assume that m is equal or smaller than n
        if(m==0) return *(nums2+k-1);
        if(k==1) return min(*nums1,*nums2);
        
        int i1=min(m,k/2),i2=k-i1;
        if(*(nums1+i1-1)<*(nums2+i2-1)){
            return __findKth(nums1+i1,m-i1,nums2,n,k-i1);
        }
        else if(*(nums1+i1-1)>*(nums2+i2-1)){
            return __findKth(nums1,m,nums2+i2,n-i2,k-i2);
        }
        else{
            return *(nums1+i1-1);
        }
    }
    
};