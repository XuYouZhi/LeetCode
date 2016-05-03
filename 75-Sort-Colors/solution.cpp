// // 方法一 泛化的双指针快速排序，两个指针向中间走 O(n)  O(1)
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         sortColors(nums,0,nums.size()-1);
//     }
    
//     void sortColors(vector<int>& nums,int l, int u){
//         int i,j;
//         if(l>=u) return;
        
//         int t=nums[l];
        
//         i=l;
//         j=u+1;
        
//         for(;;){
//             do i++; while(i<=u&&nums[i]<t);
//             do j--; while(nums[j]>t); //不用哨兵j>=0 因为 x[0]!>t
//             if(i>j) break;
//             swap(nums[i],nums[j]);
//         }
//         swap(nums[l],nums[j]);
        
//         sortColors(nums,l,j-1);
//         sortColors(nums,j+1,u);
//     }
// };


// 方法二 针对本题的双指针快速排序  O(n)  O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0,blue=nums.size()-1;
        
        for(int i=0;i<blue+1;){
            if(nums[i]==0){
                swap(nums[i++],nums[red++]);
            }
            else if(nums[i]==2){
                swap(nums[i],nums[blue--]); //注意交换后不要自增i
            }
            else
            {
                ++i;
            }
        }
    }
};
