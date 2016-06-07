// 代码一 动态规划  O(n^2)  O(n)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows<1) return result;
        
        vector<int> f(numRows,1);
        for(int r=0;r<numRows;++r){
            for(int c=r-1;c>=1;--c){
                f[c]=f[c-1]+f[c];
            }
            
            result.push_back(vector<int>());
            for(int i=0;i<=r;++i){
                result.back().push_back(f[i]);
                //cout<<f[i]<<" "; 
            }
            //cout<<endl;
        }
        
        return result;
    }
};