// // 代码一 用hash表记录每个元素是否使用，对每个元素，以该元素为中心往左右扩张，直到不连续为止，记录最长长度  O(n) O(n)
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_map<int,bool> used;
        
//         for(auto i:nums) used[i]=false;
        
//         int longest=0;
        
//         for(auto i:nums){
//             if(used[i]==true) continue;
            
//             int length=1;
//             used[i]=true;
            
//             for(int j=i+1;used.find(j)!=used.end();++j){
//                 used[j]=true;
//                 ++length;
//             }
            
//             for(int j=i-1;used.find(j)!=used.end();--j){
//                 used[j]=true;
//                 ++length;
//             }
            
//             longest=max(longest,length);
//         }
        
//         return longest;
//     }
// };


// 代码二 两端记录连续序列 O(n) O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;
        int size=nums.size();
        
        int longest=1;
        for(int i=0;i<size;++i){
            if(map.find(nums[i])!=map.end()) continue;
            map[nums[i]]=1;
            if(map.find(nums[i]-1)!=map.end()){
                longest=max(longest,mergeCluster(map,nums[i]-1,nums[i]));
            }
            if(map.find(nums[i]+1)!=map.end()){
                longest=max(longest,mergeCluster(map,nums[i],nums[i]+1));
            }
        }
        
        return size==0?0:longest;
    }
    
    
private:
    int mergeCluster(unordered_map<int,int> &map,int left, int right){
        int upper=right+map[right]-1;
        int lower=left-map[left]+1;
        int length=upper-lower+1;
        map[upper]=length;
        map[lower]=length;
        return length;
    }
};