// // Not Work， Not A Good Idear, 太麻烦
// class Solution {
// public:
//     bool isNumber(string s) {
//         if(s.length()<1) return false;
//         size_t first=s.find_first_not_of(' ');
//         size_t last=s.find_last_not_of(' ');
//         if(first==std::string::npos||last==string::npos) return false;  // Be Careful
//         s=s.substr(first,last-first+1);
        
//         const int n=s.size();
//         if(n<1) return false;
        
//         bool dot_used=false;
//         bool e_used=false;
        
//         bool result=true;
//         for(int i=0;i<n;++i){
//             if((s[i]<'0'||s[i]>'9')&&s[i]!='e'&&s[i]!='E'&&s[i]!='.'&&s[i]!='+'&&s[i]!='-'){
//                 result=false;
//                 break;
//             }
//             else if(s[i]=='.'){
//                 if(dot_used){
//                     result=false;
//                     break;
//                 }
                
//                 if(i>0&&((s[i-1]<'0'||s[i-1]>'9')&&s[i-1]!='+'&&s[i-1]!='-')){ //保证.前面有数字,+或者-   
//                     result=false;
//                     break;
//                 }
                
//                 if(i==0&&(s[i+1]<'0'||s[i+1]>'9')){//如果.前面没有数字，保证后面跟数字
//                     result=false;
//                     break;
//                 }
                
//                 if(i>0&&i+1==n&&(s[i-1]=='+'||s[i-1]=='-')){
//                     result=false;
//                     break;
//                 }
                
//                 dot_used=true;
//             }
//             else if(s[i]=='e'||s[i]=='E'){
//                 if(i<1){
//                     result=false;
//                     break;
//                 }
                
//                 if(e_used){
//                     result=false;
//                     break;
//                 }
                
                
//                 if(i+1>=n||(s[i+1]<'0'||s[i+1]>'9')){  //e后面要有数字
//                     result=false;
//                     break;
//                 }
                
//                 e_used=true;
//                 dot_used=true; //e后面不能再接.
//             }
//             else if(s[i]=='+'||s[i]=='-'){
//                 if(i>0&&s[i-1]!='e'&&s[i-1]!='E'){
//                     result=false;
//                     break;
//                 }
                
//               //if(i==0&&)
//             }
//         }
        
//         return result;
//     }
// };



// // 方法一  利用库里的strtod()
// class Solution {
// public:
//     bool isNumber(string s) {
//         return isNumber(s.c_str());
//     }
    
//     bool isNumber(const char* s){
//         char* endptr;
//         strtod(s,&endptr);  // 函数原型double strtod (const char* str, char** endptr)
        
//         if(endptr==s) return false;
        
//         for(;*endptr;++endptr){
//             if(!isspace(*endptr)) return false;
//         }
        
//         return true;
//     }
// };


// 方法二  有限自动机
class Solution {
public:
    bool isNumber(string s) {
        enum InputType {  
            INVALID,        // 0 Include: Alphas, '(', '&' ans so on  
            SPACE,          // 1  
            SIGN,           // 2 '+','-'  
            DIGIT,          // 3 numbers  
            DOT,            // 4 '.'  
            EXPONENT,       // 5 'e' 'E'  
        };  
        int transTable[][6] = {  
        //0INVA,1SPA,2SIG,3DI,4DO,5E  
            -1,  0,  3,  1,  2, -1,//0初始无输入或者只有space的状态  
            -1,  8, -1,  1,  4,  5,//1输入了数字之后的状态  
            -1, -1, -1,  4, -1, -1,//2前面无数字，只输入了Dot的状态  
            -1, -1, -1,  1,  2, -1,//3输入了符号状态  
            -1,  8, -1,  4, -1,  5,//4前面有数字和有dot的状态  
            -1, -1,  6,  7, -1, -1,//5'e' or 'E'输入后的状态  
            -1, -1, -1,  7, -1, -1,//6输入e之后输入Sign的状态  
            -1,  8, -1,  7, -1, -1,//7输入e后输入数字的状态  
            -1,  8, -1, -1, -1, -1,//8前面有有效数输入之后，输入space的状态  
        };  
        int state = 0;  
        int i=0;
        while (s[i]) {  
            InputType input = INVALID;  
            if (s[i] == ' ') input = SPACE;  
            else if (s[i] == '+' || s[i] == '-') input = SIGN;  
            else if (isdigit(s[i])) input = DIGIT;  
            else if (s[i] == '.') input = DOT;  
            else if (s[i] == 'e' || s[i] == 'E') input = EXPONENT;  
            state = transTable[state][input];  
            if (state == -1) return false;  
            ++i;  
        }  
        return state == 1 || state == 4 || state == 7 || state == 8;  
    }  
        
};


