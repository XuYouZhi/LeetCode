// 方法一 暴力破解  将最后一位、最后二位.. 反转后插入头部判断是否回文

// 方法二 KMP  
/* 思路：整个字符串反转后插入头部，但可能会有重复，比如abadc，反转后插入头部为：cdadaadadc，其中aba重复，可以看出aba分别是两个字符串的前缀      和后缀，可用KMP快速解决：将反转后的连接到后面：abadccdaba，求其前后缀相同长度，为了避免aa出现aaaa的情况，中间插入一个字符，即：
         abadc#cdaba
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length()<=1) return s;
        
        string reverseS=s;
        reverse(reverseS.begin(),reverseS.end());
        
        string str=s+"#"+reverseS;
        
        vector<int> next(str.length(),0);
        compute_prefix(str.c_str(),next);
        
        string result;
        result=reverseS.substr(0,s.length()-next[str.length()-1]-1)+s;
        return result;
    }
    
    void compute_prefix(const char *pattern, vector<int>& next){
        int i=0;
        int j=-1;
        const int n=strlen(pattern);
        
        next[0]=j;
        for(int i=1;i<n;++i){
            while(j>-1&&pattern[j+1]!=pattern[i]) j=next[j];
            if(pattern[j+1]==pattern[i]) ++j;
            next[i]=j;
        }
    }
};