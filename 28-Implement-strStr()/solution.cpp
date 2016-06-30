// //方法一 暴力匹配，Time Limit Exceeded  O(M*N)  O(1)
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         if(needle.size()<1){
//             return 0;
//         }
        
//         for(int i=0;i<haystack.size()-needle.size()+1;++i){
//             int j=i;
//             int k=0;
//             while(j<haystack.size()&&k<needle.size()&&haystack[j]==needle[k]){ 
//                 ++j;++k;
//             }
//             if(k==needle.size()){
//                 return i;
//             }
//         }
        
//         return -1;
//     }
// };
    


// 方法二 KMP  O(M+N)  O(M)
class Solution {
public:
    int strStr(string haystack,string needle){
        return kmp(haystack.c_str(),needle.c_str());
    }
    
private:
    void compute_prefix(const char *pattern,int next[]){
        int i;
        int j=-1;
        const int n=strlen(pattern);
        
        next[0]=j;
        for(int i=1;i<n;++i){
            while(j>-1&&pattern[j+1]!=pattern[i]) j=next[j];
            if(pattern[j+1]==pattern[i]) j++;
            next[i]=j;
        }
    }
    
    int kmp(const char* text, const char* pattern){
        int i;
        int j=-1;
        const int n=strlen(text);
        const int m=strlen(pattern);
        
        if(n==0&&m==0) return 0;
        if(m==0) return 0;
        
        int* next=new int[m];
        
        compute_prefix(pattern,next);
        
        for(int i=0;i<n;++i){
            while(j>-1&&pattern[j+1]!=text[i]) j=next[j];
            if(text[i]==pattern[j+1]) j++;
            
            if(j==m-1){
                delete []next;
                return i-j;
            }
        }
        
        delete []next;
        return -1;
    }
};