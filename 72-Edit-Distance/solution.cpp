// // 方法一 Not Work 动手前先思考好可行性   abccd   aabdefd  ccd中cd之间可以插入f
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         vector<vector<int>> word1_map('a'+256);
//         vector<vector<int>> word2_map('a'+256);
        
//         const int word1_len=word1.length();
//         const int word2_len=word2.length();
        
//         if(word1_len==0||word2_len==0){
//             return max(word1_len,word2_len);
//         }
        
//         for(int i=0;i<word1_len;++i){
//             word1_map[word1[i]].push_back(i);
//         }
        
//         for(int i=0;i<word2_len;++i){
//             word2_map[word2[i]].push_back(i);
//         }
        
//         map<int,vector<int>> distance_count;
        
//         for(int i=0;i<word1_len;++i){
//             char key=word1[i];
//             if(word2_map[key].size()>0){
//                 for(int w1=0;w1<word1_map[key].size();++w1){
//                     for(int w2=0;w2<word2_map[key].size();++w2){
//                         int distance_key=word2_map[key][w2]-word1_map[key][w1];
//                         if(distance_count.find(distance_key)!=distance_count.end()){
//                             distance_count[distance_key][0]+=1;
//                         }
//                         else{
//                             distance_count[distance_key].push_back(1);
//                             distance_count[distance_key].push_back(word1_map[key][w1]);
//                             distance_count[distance_key].push_back(word2_map[key][w2]);
//                         }
                        
//                     }
//                 }
//             }
//         }

//         int max_len=0;
//         int dis_key=0;
//         for(auto dis:distance_count){
//             if(dis.second[0]>max_len){
//                 max_len=dis.second[0];
//                 dis_key=dis.first;
//             }
//         }
        
        
//         return max(distance_count[dis_key][1],distance_count[dis_key][2])+max(word1_len-max_len-distance_count[dis_key][1],word2_len-max_len-distance_count[dis_key][2]);
//     }
    
// };


// 方法二 动态规划  O(n*m)  O(n*m)
// f[i][j]表示 A[0,i]和B[0,j]之间的最小编辑距离, 设 c d为对应 A B 中的char
// 1 如果c==d  f[i][j]=f[i-1][j-1]  2 c!=d  f[i][j]=min(x,y,z)  x=f[i-1][j-1]+1(c替换d)  y=f[i][j-1]+1(c后插入一个d)  z=f[i-1][j]+1
class Solution {
public:
    int minDistance(string word1, string word2) {
        const size_t m=word1.size();
        const size_t n=word2.size();
        
        int f[m+1][n+1];
        for(size_t i=0;i<=m;++i){
            f[i][0]=i;
        }
        for(size_t j=0;j<=n;++j){
            f[0][j]=j;
        }
        
        
        for(size_t i=1;i<=m;++i){
            for(size_t j=1;j<=n;++j){
                if(word1[i-1]==word2[j-1]){
                    f[i][j]=f[i-1][j-1];
                }
                else{
                    int tmp=min(f[i-1][j-1],f[i][j-1]);
                    f[i][j]=min(tmp,f[i-1][j])+1;
                }
            }
        }
        
        return f[m][n];
    }
};
