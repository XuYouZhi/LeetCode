// ab aa ; ab ca
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int n=s.length();
        if(n<=0) return true;
        
        unordered_map<char,char> map;
        unordered_set<char> repeated;
        
        for(int i=0;i<n;++i){
            if(map.find(s[i])==map.end()){
                if(repeated.find(t[i])==repeated.end()){
                    map[s[i]]=t[i];
                    repeated.insert(t[i]);
                }
                else{
                    return false;
                }
            }
            else{
                if(map[s[i]]!=t[i]) return false;
            }
        }
        
        return true;
    }
};