// 代码一 动态规划  O(n^2)  O(n)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        
        vector<int> f(rowIndex+1,1);
        for(int r=0;r<=rowIndex;++r){
            for(int c=r-1;c>=1;--c){
                f[c]=f[c-1]+f[c];
            }
        }
        
        for(int i=0;i<=rowIndex;++i){
            result.push_back(f[i]);
        }
        
        return result;
    }
};