// // 代码一 递归 Time Limit Exceeded 
// class Solution {
// public:
//     int calculateMinimumHP(vector<vector<int>>& dungeon) {
//         int result=INT_MAX;
//         int minhp=1;
//         walk(dungeon, result,minhp,0,0,0);
//         return result;
//     }
    
//     void walk(vector<vector<int>>& dungeon, int& result, int minhp, int curhp, int x, int y){
//         const int m=dungeon.size();
//         const int n=dungeon[0].size();
        
//         if(x>m-1||y>n-1) return;
        
//         if(curhp+dungeon[x][y]<=0){
//             minhp=max(minhp,abs(curhp+dungeon[x][y])+1);
//         }
        
//         if(minhp>=result) return;
        
//         if(x==m-1&&y==n-1){
//             if(minhp<result){
//                 result=minhp;
//             }
//             return;
//         }
        
//         if(x<m-1){
//             walk(dungeon,result,minhp,curhp+dungeon[x][y],x+1,y);
//         }
        
//         if(y<n-1){
//             walk(dungeon,result,minhp,curhp+dungeon[x][y],x,y+1);
//         }
        
//     }
// };



/*
思路：建立一个和迷宫大小相同的二维数组用来表示当前位置出发的起始血量，最先初始化的是公主所在的房间的起始生命值，然后慢慢向第一个房间扩散，   不断的得到各个位置的最优的起始生命值。
*/
// 代码二 动态规划  递归方程 dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j])
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int m=dungeon.size();
        const int n=dungeon[0].size();
        
        int dp[m][n];
        dp[m-1][n-1]=max(1,1-dungeon[m-1][n-1]);
        for(int i=m-2;i>=0;--i){
            dp[i][n-1]=max(1,dp[i+1][n-1]-dungeon[i][n-1]);
        }
        for(int j=n-2;j>=0;--j){
            dp[m-1][j]=max(1,dp[m-1][j+1]-dungeon[m-1][j]);
        }
        
        for(int i=m-2;i>=0;--i){
            for(int j=n-2;j>=0;--j){
                dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
};