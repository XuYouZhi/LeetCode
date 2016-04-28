class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        const int row=matrix.size();
        if(row<1) return result;
        const int col=matrix[0].size();
        if(col<1) return result;
        
        int start=0;
        
        while(start*2<col&&start*2<row){
            spiralOrder(matrix,col,row,start,result);
            ++start;
        }
        
        return result;
    }
    
    void spiralOrder(const vector<vector<int>>& matrix, int col, int row, int start,vector<int>& result){
        int endx=col-1-start;
        int endy=row-1-start;
        
        for(int i=start;i<=endx;++i){ // 从左到右 
            result.push_back(matrix[start][i]);
        }
        
        if(endy>start){
            for(int i=start+1;i<=endy;++i){ // 从上到下
                result.push_back(matrix[i][endx]);
            }
        }
        
        if(endx>start&&endy>start){ // 从右到左
            for(int i=endx-1;i>=start;--i){
                result.push_back(matrix[endy][i]);
            }
        }
        
        if(endx>start&&endy>start+1){ // 从下到上
            for(int i=endy-1;i>=start+1;--i){
                result.push_back(matrix[i][start]);
            }
        }
    }
};