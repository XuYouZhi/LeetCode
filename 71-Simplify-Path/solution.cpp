class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        
        // 非STL版本
        const int n=path.length();
        for(int i=0;i<n;){
            ++i;
            
            size_t j=path.find('/',i);
            if(j==string::npos) j=n; //注意找不到返回-1，不像STL返回END
            
            string dir=path.substr(i,j-i);
            
            if(!dir.empty()&&dir!="."){
                if(dir==".."){
                    if(!dirs.empty()){
                        dirs.pop_back();
                    }
                }
                else{
                    dirs.push_back(dir);
                }
            }
            
            i=j;
        }
        
        stringstream out;
        if(dirs.empty()){
            out<<"/";
        }
        else{
            for(int i=0;i<dirs.size();++i){
                out<<"/"<<dirs[i];
            }
        }
        
        return out.str();
        
        
        // //STL版本
        // for(auto i=path.begin();i!=path.end();){
        //     ++i;
            
        //     auto j=find(i,path.end(),'/');
            
        //     auto dir=string(i,j);
            
        //     if(!dir.empty()&&dir!="."){
        //         if(dir==".."){
        //             if(!dirs.empty()){
        //                 dirs.pop_back();
        //             }
        //         }
        //         else{
        //             dirs.push_back(dir);
        //         }
        //     }
            
        //     i=j;
        // }
        
        // stringstream out;
        // if(dirs.empty()){
        //     out<<"/";
        // }
        // else{
        //     for(auto dir:dirs){
        //         out<<"/"<<dir;
        //     }
        // }
        
        // return out.str();
        
        
        
    }
};