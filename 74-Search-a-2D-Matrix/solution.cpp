// 二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found=false;
        
        int row_size=matrix.size();
        if(row_size<1){
            return found;
        }
        int col_size=matrix[0].size();
        if(col_size<1){
            return found;
        }
        
        int low=0,high=row_size*col_size-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int value=matrix[mid/col_size][mid%col_size];
            
            if(value>target){
                high=mid-1;
            }
            else if(value<target){
                low=mid+1;
            }
            else
            {
                found=true;
                break;
            }
        }
        
        return found;
    }
};