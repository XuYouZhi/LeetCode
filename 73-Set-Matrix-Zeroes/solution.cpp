class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m=matrix.size();
        if(m<1) return;
        const int n=matrix[0].size();
        
        int f[m+n];
        fill(f,f+m+n,1);
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]==0){
                    f[i]=0;
                    f[m+j]=0;
                }
            }
        }
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                matrix[i][j]=(f[i]==0||f[m+j]==0)?0:matrix[i][j];
            }
        }
        
    }
};