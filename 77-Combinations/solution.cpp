// // 方法一 递归  O(n!)  O(n)
// class Solution {
// public:
//     vector<vector<int>> combine(int n, int k) {
//         if(k>n) return vector<vector<int>>();
        
//         vector<vector<int>> result;
//         vector<int> path;
        
//         combine(result,path,n,k,0);
        
//         return result;
//     }
    
//     void combine(vector<vector<int>>& result, vector<int>& path, int n, int k, int start){
//         if(k==0){
//             result.push_back(path);
//             return;
//         }
        
//         for(int i=start;i<n;++i){
//             path.push_back(i+1);
//             --k;
            
//             combine(result,path,n,k,i+1);
            
//             path.pop_back();
//             ++k;
//         }
//     }
// };


// 方法二 迭代 利用了prev_permutation()  O((n-k)!)  O(n) 
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> values(n);
        iota(values.begin(),values.end(),1);
        
        vector<int> select(n,false);
        fill_n(select.begin(),k,true);
        
        vector<vector<int>> result;
        do{
            vector<int> one(k);
            
            for(int i=0,index=0;i<n;++i){
                if(select[i]){
                    one[index++]=values[i];
                }
            }
            
            result.push_back(one);
        }while(prev_permutation(select.begin(),select.end()));
        
        return result;
    }
};



