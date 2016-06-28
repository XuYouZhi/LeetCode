// 方法一  构建一个新数组 O(n)  O(n)  不满足就地旋转 略


// // 方法二  反转整个数组，反转前k个，反转后k个 O(n) O(1)
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         const int n=nums.size();
//         k=k%n;
        
//         reverse(nums.begin(),nums.end());
//         reverse(nums.begin(),next(nums.begin(),k));
//         reverse(next(nums.begin(),k),nums.end());
//     }
// };


// 方法三 将元素循环移动 O(n) O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n=nums.size();
        int idx=0, distance=0;
        int cur=nums[0];
        int tmp;
        for(int i=0;i<n;++i){
            idx=(idx+k)%n;
            tmp=nums[idx];
            nums[idx]=cur;
            cur=tmp;
            
            distance=(distance+k)%n;
            if(distance==0){ // 用来处理类似[1,2,3,4,5,6] 2的这种情况
                idx=(idx+1)%n;
                cur=nums[idx];
            }
        }
    }
};
