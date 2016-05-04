class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(k>n) return vector<vector<int>>();
        
        vector<vector<int>> result;
        vector<int> path;
        
        combine(result,path,n,k,0);
        
        return result;
    }
    
    void combine(vector<vector<int>>& result, vector<int>& path, int n, int k, int start){
        if(k==0){
            result.push_back(path);
            return;
        }
        
        for(int i=start;i<n;++i){
            path.push_back(i+1);
            --k;
            
            combine(result,path,n,k,i+1);
            
            path.pop_back();
            ++k;
        }
    }
};