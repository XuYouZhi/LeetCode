// 代码一  遍历 O(n) O(n)  还有一种找数学规律的方法，不予赘述
class Solution {
public:
    string convert(string s, int numRows) {
        const int size=s.size();
        if(size==0||numRows==1||size<=numRows){
            return s;
        }
        
        vector<string> r(numRows);
        int row=0,step=1;
        for(int i=0;i<size;++i){
            if(row==0) step=1;
            if(row==numRows-1) step=-1;
            r[row]+=s[i];
            row+=step;
        }
        
        string result;
        for(int i=0;i<numRows;i++){
            result+=r.at(i);
        }
        return result;
    }
};