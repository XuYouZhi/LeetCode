// // 方法一 动态规划法 f[i][j] 表示从起点到(i,j)的最小SUM  状态转移：f[i][j]=min(f[i-1][j],f[i][j-1])
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         const int m=grid.size();
//         if(m<1) return 0;
//         const int n=grid[0].size();
        
//         int f[m][n];
//         f[0][0]=grid[0][0];
        
//         for(int i=1;i<m;++i){
//             f[i][0]=f[i-1][0]+grid[i][0];
//         }
        
//         for(int j=1;j<n;++j){
//             f[0][j]=f[0][j-1]+grid[0][j];
//         }
        
//         for(int i=1;i<m;++i){
//             for(int j=1;j<n;++j){
//                 f[i][j]=min(f[i-1][j],f[i][j-1])+grid[i][j];
//             }
//         }
        
//         return f[m-1][n-1];
//     }
// };


// 方法二 动态规划+滚动数组
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m=grid.size();
        if(m<1) return 0;
        const int n=grid[0].size();
        
        int f[n]; //不可以这样初始化：int f[n]={INT_MAX};
        fill(f,f+n,INT_MAX);
        f[0]=0;
        
        for(int i=0;i<m;++i){
            f[0]+=grid[i][0];
            for(int j=1;j<n;++j){
                // 右边的f[j]表示更新后的f[j], 对应公式中的f[i][j]
                // 左边的f[j]表示之前的f[j],对应公式中的f[i-1][j]; f[j-1]对应f[i][j-1]
                f[j]=min(f[j],f[j-1])+grid[i][j];
            }
        }
        
        return f[n-1];
    }
};
