class Solution {
private:
    unordered_map<int,vector<int>> course;
    
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        for(int i=0;i<prerequisites.size();++i){
            int first=prerequisites[i].first, second=prerequisites[i].second;
            if(course.find(first)==course.end()){
                course[first]=vector<int>();
            }
            course[first].push_back(second);
        }
        
        unordered_map<int,vector<int>>::iterator iter;
        for(iter=course.begin();iter!=course.end();++iter){
            int start=(*iter).first;
            unordered_set<int> checked;
            if(dfs(start, checked)==false) return false;
        }
        
        return true;
    }
    
    bool dfs(int start, unordered_set<int> checked){
        checked.insert(start);
        for(auto s:course[start]){
            cout<<s<<" "<<start<<endl;
            if(checked.find(s)!=checked.end()) return false;
            if(dfs(s,checked)==false) return false;
        }
        
        return true;
    }
};