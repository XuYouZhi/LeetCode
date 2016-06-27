class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1, v2;
        
        for(int i=0;i<version1.size();++i){
            if(v1.empty()||version1[i]=='.'){
                v1.push_back("");
            }
            if(version1[i]=='.') continue;
            
            v1.back().push_back(version1[i]);
        }
        for(int i=0;i<version2.size();++i){
            if(v2.empty()||version2[i]=='.'){
                v2.push_back("");
            }
            if(version2[i]=='.') continue;
            
            v2.back().push_back(version2[i]);
        }
        
        int len=0;
        int len1=v1.size(), len2=v2.size();
        if(len1<len2){
            len=len2;
            for(int i=len1;i<len;++i){
                v1.push_back("0");
            }
        }
        else if(len1>len2){
            len=len1;
            for(int i=len2;i<len;++i){
                v2.push_back("0");
            }
        }
        else{
            len=len1;
        }
        
        for(int i=0;i<len;++i){
            if(stoi(v1[i])<stoi(v2[i])){
                return -1;
            }
            else if(stoi(v1[i])>stoi(v2[i])){
                return 1;
            }
        }
        
        return 0;
    }
};