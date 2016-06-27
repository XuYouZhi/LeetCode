// 桶排序 
/*
设从A到B有N个元素  最大的gap不会小于ceiling((B-A)/(N-1))  让一个桶装len=ceiling((B-A)/(N-1))个元素  则最多会有(B-A)/len+1个桶
将每个元素放入对应的桶中 loc=(K-A)/len  由于每个桶内最大的gap是len-1，则所有元素中最大的gap不会在桶内，只会在桶间
对每个非空桶p，找到下一个非空q，q.min-p.max可能为答案，遍历后可找到最大的gap
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int n=nums.size();
        if(n<2) return 0;
        
        int max_num=nums[0], min_num=nums[0];
        for(auto i:nums){
            max_num=max(max_num,i);
            min_num=min(min_num,i);
        }
        
        if(max_num==min_num) return 0;
        
        int len=ceil((max_num-min_num)/double(n-1)); //(max_num-min_num)/n+1;  (max_num-min_num-1)/(n-1)+1; 不同的ceil方式 
        
        vector<vector<int>> buckets((max_num-min_num)/len+1); //桶的个数
        for(auto i:nums){
            int j=(i-min_num)/len;
            if(buckets[j].empty()){
                buckets[j].reserve(2);
                buckets[j].push_back(i);
                buckets[j].push_back(i);
            }
            else{
                if(i<buckets[j][0]) buckets[j][0]=i;
                if(i>buckets[j][0]) buckets[j][1]=i;
            }
        }
        
        int gap=0, prev=0;
        for(int i=1;i<buckets.size();++i){
            if(buckets[i].empty()) continue;
            gap=max(gap,buckets[i][0]-buckets[prev][1]);
            prev=i;
        }
        
        return gap;
    }
};