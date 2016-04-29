class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        if(n<1) return result;
        
        result=vector<vector<int>>(n,vector<int>(n,0));
        
        int start=0;
        int number=1;
        while(start*2<n){
            fillMatrix(result,number,start);
            ++start;
        }
        
        return result;
    }
    
    void fillMatrix(vector<vector<int>>& result, int& number, int start){
        int end=result.size()-1-start;
        
        
        for(int i=start;i<=end;++i){
            result[start][i]=number++;
        }
        
        if(end>start){
            for(int i=start+1;i<=end;++i){
                result[i][end]=number++;
            }
        }
        
        if(end>start){
            for(int i=end-1;i>=start;--i){
                result[end][i]=number++;
            }
        }
        
        if(end>start+1){
            for(int i=end-1;i>=start+1;--i){
                result[i][start]=number++;
            }
        }
    }
};