class Solution {
public:
    // // 方法一 using map  100ms
    // int lengthOfLongestSubstring(string s) {
    //     map<char,int> m;
        
    //     int max_len=0;
    //     int last_repeat_pos=-1;
    //     for(int i=0;i<s.size();++i){
    //         if(m.find(s[i])!=m.end()&&last_repeat_pos<m[s[i]]){
    //             last_repeat_pos=m[s[i]];
    //         }
    //         if(i-last_repeat_pos>max_len){
    //             max_len=i-last_repeat_pos;
    //         }
    //         m[s[i]]=i;
    //     }
        
    //     return max_len;
    // }
  
    // 方法二 not using map  16ms
    int lengthOfLongestSubstring(string s) {
        const int MAX_CHARS=256;
        
        int m[MAX_CHARS];
        memset(m,-1,sizeof(m));
        
        int max_len=0;
        int last_repeat_pos=-1;
        for(int i=0;i<s.size();i++){
            if(last_repeat_pos<m[s[i]]){
                last_repeat_pos=m[s[i]];
            }    
            if(i-last_repeat_pos>max_len){
                max_len=i-last_repeat_pos;
            }
            m[s[i]]=i;
        }
        
        return max_len;
    }
    
};