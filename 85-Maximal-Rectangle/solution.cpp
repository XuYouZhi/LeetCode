class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int m=matrix.size();
        if(m<1) return 0;
        const int n=matrix[0].size();
        
        //转化为直方图
        vector<vector<int>> heights(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0'){
                    heights[i][j]=0;
                }
                else{
                    heights[i][j]=(i==0)?1:heights[i-1][j]+1;
                }
            }
        }
        
        int result=0;
        for(int i=0;i<m;i++){
            result=max(result,largestRectangleArea(heights[i]));
        }
        
        return result;
    }
    
    //求直方图最大面积 O(n) O(n)
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        
        int result=0;
        for(int i=0;i<heights.size();){
            if(s.empty()||heights[i]>heights[s.top()]){
                s.push(i++);
            }
            else{
                int tmp=s.top();
                s.pop();
                result=max(result,heights[tmp]*(s.empty()?i:i-s.top()-1));
            }
        }
        
        return result;
    }
};