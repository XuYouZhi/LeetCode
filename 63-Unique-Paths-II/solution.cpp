// 方法一 动态规划  f[i][j] 表示从起点到(i,j)的路径条数  状态转移：f[i][j]=f[i-1][j]+f[i][j-1]
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m=obstacleGrid.size();
        if(m<1) return 0;
        const int n=obstacleGrid[0].size();
        
        vector<vector<int>> f(m,vector<int>(n,0));
             
             
        for(int i=0;i<m;++i){
            if(obstacleGrid[i][0]==1) break;
            f[i][0]=1;
        }  
        for(int j=0;j<n;++j){
            if(obstacleGrid[0][j]==1) break;
            f[0][j]=1;
        }

    
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(obstacleGrid[i][j]==1){
                    f[i][j]=0;
                }
            }
        }
        
        
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                if(obstacleGrid[i][j]!=1){
                    f[i][j]=f[i-1][j]+f[i][j-1];
                }
            }
        }
        
        return f[m-1][n-1];
    }
};