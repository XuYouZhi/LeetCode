// // 代码一
// class Solution {
// public:
//     int titleToNumber(string s) {
//         int result=0;
//         reverse(s.begin(),s.end());
        
//         for(int i=0;i<s.size();++i){
//             result+=(s[i]-'A'+1)*pow(26,i); // 注意不要用powf
//         }
        
//         return result;
//     }
// };


// 代码二
class Solution {
public:
    int titleToNumber(string s) {
        int result=0;
        int tmp=0;
        for(int i=0;i<s.size();++i){
            tmp=s[i]-'A'+1;
            result=result*26+tmp;
        }
        
        return result;
    }
};