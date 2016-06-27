// // 代码一 递归
// class Solution {
// public:
//     string convertToTitle(int n) {
//         if(n==0) return "";
        
//         return convertToTitle((n-1)/26)+char((n-1)%26+'A');
//     }
// };


// 代码二 迭代
class Solution {
public:
    string convertToTitle(int n) {
        string result="";
        
        // while(n){
        //     int r=n%26;
        //     n/=26;
            
        //     if(r==0){ //26 
        //         result+='Z';
        //         --n;
        //     }
        //     else{
        //         result+=r-1+'A';
        //     }
            
        // }
        
        while(n){
            int r=(n-1)%26;
            n=(n-1)/26;
            result+=(r+'A');
        }
        
        
        reverse(result.begin(),result.end());  
        
        return result;
    }
};