// // 代码一 递归  Time Limit Exceeded O(n)
// class Solution {
// public:
//     int numDecodings(string s) {
//         if(s.size()<1) return 0;
//         return numDecodings(s,0);
//     }
    
// private:
//     int numDecodings(string s, int start){
//         if(start>=s.size()-1) return 1;
        
//         if(s[start]=='1'||(s[start]=='2'&&s[start+1]-'0'<=6)){
//             return numDecodings(s,start+1)+numDecodings(s,start+2);
//         }
//         else{
//             return numDecodings(s,start+1);
//         }
//     }
// };



// 代码二 动态规划 O(n) O(1)
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()||s[0]=='0') return 0;
        
        int prev=0; //f(n-2)
        int cur=1; //f(n-1)
        
        for(size_t i=1;i<=s.size();++i){
            if(s[i-1]=='0') cur=0;
            if(i<2||!(s[i-2]=='1'||(s[i-2]=='2'&&s[i-1]<='6'))) prev=0;
            
            int tmp=cur;
            cur=prev+cur;
            prev=tmp;
        }
        return cur;
    }
};