// 代码一 递归版 O(2^n) O(n)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> result;
        vector<int> path;
        
        dfs(nums,nums.begin(),path,result);
        return result;
    }
    
private:
    static void dfs(const vector<int>& nums, vector<int>::iterator start, vector<int>& path, vector<vector<int>>& result){
        result.push_back(path);
        
        for(auto i=start;i<nums.end();++i){
            if(i!=start&&*(i)==*(i-1)) continue;
            path.push_back(*i);
            dfs(nums,i+1,path,result);
            path.pop_back();
        }
    }
};