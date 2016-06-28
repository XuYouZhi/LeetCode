// 方法一  构建一个新数组 O(n)  O(n)  不满足就地旋转 略
// 方法二  反转整个数组，反转前k个，反转后k个
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n=nums.size();
        k=k%n;
        
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),next(nums.begin(),k));
        reverse(next(nums.begin(),k),nums.end());
    }
};