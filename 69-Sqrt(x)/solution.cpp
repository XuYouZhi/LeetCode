// // 方法一  Time Limit Exceeded
// class Solution {
// public:
//     int mySqrt(int x) {
//         if(x==0) return 0;
        
//         int start=x/2;
//         while(start*start>x){
//             start/=2;
//         }
        
//         int i=start;
//         for(;i<x;++i){
//             if(i*i>x){
//                 break;
//             }
//         }
        
//         return i-1;
//     }
// };



// 方法二  二分查找 O(logn), O(1)
class Solution {
public:
    int mySqrt(int x) {
        int left=1, right=x/2;
        int last_mid;
        
        if(x<2) return x;
        
        while(left<=right){
            const int mid=left+(right-left)/2; // 不用mid=(left+right)/2;是由于担心left+right越界。
            if(x/mid>mid){ // 不用x>mid*mid，避免溢出
                left=mid+1;
                last_mid=mid;
            }
            else if(x/mid<mid){
                right=mid-1;
            }
            else{
                return mid;
            }
        }
        
        return last_mid;
    }
};