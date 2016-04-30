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



// 方法一  利用库里的strtod()
class Solution {
public:
    bool isNumber(string s) {
        return isNumber(s.c_str());
    }
    
    bool isNumber(const char* s){
        char* endptr;
        strtod(s,&endptr);  // 函数原型double strtod (const char* str, char** endptr)
        
        if(endptr==s) return false;
        
        for(;*endptr;++endptr){
            if(!isspace(*endptr)) return false;
        }
        
        return true;
    }
};


