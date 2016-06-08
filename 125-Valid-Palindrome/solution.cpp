// O(n)  O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        
        int idx=0;
        for(int i=0;i<s.size();++i){
            if(s[i]>='a'&&s[i]<='z'){
                s[idx++]=s[i];
            }
            else if(s[i]>='A'&&s[i]<='Z'){
                s[idx++]=s[i]+32;
            }
            else if(s[i]>='0'&&s[i]<='9'){
                s[idx++]=s[i];
            }
            else{
                
            }
        }
        s=s.substr(0,idx);
        
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        
        return true;
    }
};