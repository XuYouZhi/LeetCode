class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()<1) return 0;
        
        int i=s.size()-1;
        while(i>=0&&s[i]==' ') --i; //注意末尾的空格
        
        int count=0;
        for(;i>=0;--i){
            if(s[i]!=' '){
                count++;
            }
            else{
                break;
            }
        }
        
        return count;
    }
};