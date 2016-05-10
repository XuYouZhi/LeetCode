// // 代码一  转化为直方图，求直方图的最大面积，O(n^2) O(n^2)
// class Solution {
// public:
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         const int m=matrix.size();
//         if(m<1) return 0;
//         const int n=matrix[0].size();
        
//         //转化为直方图
//         vector<vector<int>> heights(m,vector<int>(n,0));
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]=='0'){
//                     heights[i][j]=0;
//                 }
//                 else{
//                     heights[i][j]=(i==0)?1:heights[i-1][j]+1;
//                 }
//             }
//         }
        
//         int result=0;
//         for(int i=0;i<m;i++){
//             result=max(result,largestRectangleArea(heights[i]));
//         }
        
//         return result;
//     }
    
//     //求直方图最大面积 O(n) O(n)
//     int largestRectangleArea(vector<int>& heights) {
//         stack<int> s;
//         heights.push_back(0);
        
//         int result=0;
//         for(int i=0;i<heights.size();){
//             if(s.empty()||heights[i]>heights[s.top()]){
//                 s.push(i++);
//             }
//             else{
//                 int tmp=s.top();
//                 s.pop();
//                 result=max(result,heights[tmp]*(s.empty()?i:i-s.top()-1));
//             }
//         }
        
//         return result;
//     }
// };


//代码二 记录每一行的1开始位置和1结束的位置，和列的height O(n^2) O(n)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        
        const int m=matrix.size();
        const int n=matrix[0].size();
        vector<int> H(n,0);
        vector<int> L(n,0);
        vector<int> R(n,n);
        
        int result=0;
        for(int i=0;i<m;i++){
            int left=0,right=n;
            
            //从左到右计算L(i,j)
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    ++H[j];
                    L[j]=max(L[j],left); // L[i][j]=max(L[i-1][j],left)
                }
                else{
                    left=j+1;
                    H[j]=0;L[j]=0;R[j]=n;    
                }
            }
            
            //从右到左计算R(i,j)
            for(int j=n-1;j>=0;--j){
                if(matrix[i][j]=='1'){
                    R[j]=min(R[j],right);
                    result=max(result,H[j]*(R[j]-L[j]));
                }
                else{
                    right=j;
                }
            }
        }
        
        return result;
    }
};
