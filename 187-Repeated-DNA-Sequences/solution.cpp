class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.length()<=10) return result;
        
        unordered_map<char, unsigned int> convert{{'A',0},{'C',1},{'G',2},{'T',3}}; // 00 01 10 11
        
        unordered_set<unsigned int> repeated, check; // repeated 看是否出现两次  check避免重复插入字符串
        
        int hash_value=0;
        for(int i=0;i<10;++i){
            hash_value<<=2;
            hash_value|=convert[s[i]];
        }
        
        repeated.insert(hash_value);
        
        for(int i=10;i<s.length();++i){
            hash_value<<=2;
            hash_value|=convert[s[i]];
            hash_value&=~(0x300000);  //0x0fffff              0000 0000 0011 0000 0000 0000 0000 0000
            
            unordered_set<unsigned int>::iterator it=repeated.find(hash_value);
            if(it!=repeated.end()){
                it=check.find(hash_value);
                if(it==check.end()){
                    result.push_back(s.substr(i-9,10));
                    check.insert(hash_value);
                }
            }
            else{
                repeated.insert(hash_value);
            }
        }
        
        return result;
    }
};