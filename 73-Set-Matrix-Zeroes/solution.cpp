// // 方法一 O(m*n)  O(m+n)
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         const int m=matrix.size();
//         if(m<1) return;
//         const int n=matrix[0].size();
        
//         int f[m+n];
//         fill(f,f+m+n,1);
        
//         for(int i=0;i<m;++i){
//             for(int j=0;j<n;++j){
//                 if(matrix[i][j]==0){
//                     f[i]=0;
//                     f[m+j]=0;
//                 }
//             }
//         }
        
//         for(int i=0;i<m;++i){
//             for(int j=0;j<n;++j){
//                 matrix[i][j]=(f[i]==0||f[m+j]==0)?0:matrix[i][j];
//             }
//         }
        
//     }
// };


// 方法一 O(m*n)  O(1) 复用第一行和第一列
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m=matrix.size();
        if(m<1) return;
        const int n=matrix[0].size();
        
        bool row_has_zero=false; // 第一行是否存在0，保留
        bool col_has_zero=false; // 第一列是否存在0
        
        for(int i=0;i<m;++i){
            if(matrix[i][0]==0){
                col_has_zero=true;
                break;
            }
        }
        for(int j=0;j<n;++j){
            if(matrix[0][j]==0){
                row_has_zero=true;
                break;
            }
        }
        
        
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        
        if(col_has_zero){
            for(int i=0;i<m;++i){
                matrix[i][0]=0;
            }
        }
        if(row_has_zero){
            for(int j=0;j<n;++j){
                matrix[0][j]=0;
            }
        }
        
    }
};