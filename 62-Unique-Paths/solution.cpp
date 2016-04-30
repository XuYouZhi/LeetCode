// // 方法一 深搜 Time Limit Exceeded O(n^4)
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         int result=0;
//         walk(m,n,0,0,result);
//         return result;
//     }
    
//     void walk(int m, int n, int col, int row,int& result){
//         if(col==n-1&&row==m-1) {++result;return;}
//         if(col>n-1) return;
//         if(row>m-1) return;
        
//         walk(m,n,col+1,row,result);
//         walk(m,n,col,row+1,result);
//     }
// };



// // 方法二 深搜 Time Limit Exceeded O(n^4)
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         if(m<1||n<1) return 0;
        
//         if(m==1&&n==1) return 1;
        
//         return uniquePaths(m-1,n)+uniquePaths(m,n-1);
//     }
// };


// 方法三 备忘录  自顶向下解决 给深搜加个缓存  O(n^2)  O(n^2)
class Solution {
public:
    int uniquePaths(int m, int n) {
        f=vector<vector<int>>(m,vector<int>(n,0));
        f[0][0]=1;
        return dfs(m-1,n-1);
    }
    
private:
    vector<vector<int>> f; 
    
    int dfs(int x,int y){
        if(x<0||y<0) return 0;
        
        if(x==0&&y==0) return f[0][0];
        
        if(f[x][y]>0){
            return f[x][y];
        }
        else{
            return f[x][y]=dfs(x-1,y)+dfs(x,y-1);
        }
    }
};


