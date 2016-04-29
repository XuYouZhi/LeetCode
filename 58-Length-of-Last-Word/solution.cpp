// //方法一
// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         if(s.size()<1) return 0;
        
//         int i=s.size()-1;
//         while(i>=0&&s[i]==' ') --i; //注意末尾的空格
        
//         int count=0;
//         for(;i>=0;--i){
//             if(s[i]!=' '){
//                 count++;
//             }
//             else{
//                 break;
//             }
//         }
        
//         return count;
//     }
// };




// 方法二
class Solution {
public:
    int lengthOfLastWord(string s) {
        return lengthOfLastWord(s.c_str());
    }
    
    int lengthOfLastWord(const char* s){
        int len=0;
        
        while(*s){
            if(*s++!=' '){  //注意*s++的顺序，同一优先级，是自右向左结合的运算符，等价于*(s++)!=' ' 即先判断t=s++  *t!=' ', 然后再++
                ++len;
            }
            else if(*s&&*s!=' '){
                len=0;
            }
        }
        
        return len;
    }
};
