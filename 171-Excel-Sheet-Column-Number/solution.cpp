class Solution {
public:
    int titleToNumber(string s) {
        int result=0;
        reverse(s.begin(),s.end());
        
        for(int i=0;i<s.size();++i){
            result+=(s[i]-'A'+1)*pow(26,i);
        }
        
        return result;
    }
};