// 代码一  DFS
/*
思路：先建立好有向图，然后从第一个门课开始，找其前驱课程，暂时将当前课程标记为已访问，然后对新得到的课程调用DFS递归，直到出现新的课程       已经访问过了（有向图有环），则返回false，没有冲突的话（无环）返回true，然后把标记当前课程无冲突（无环，如果一个课程的前驱课程为该课   程，直接返回无冲突）
*/
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
        unordered_map<int,int> checked;
        for(iter=course.begin();iter!=course.end();++iter){
            checked[(*iter).first]=0;
        }
        
        for(iter=course.begin();iter!=course.end();++iter){
            int start=(*iter).first;
            if(dfs(start, checked)==false) return false;
        }
        
        return true;
    }
    
    bool dfs(int start, unordered_map<int,int> &checked){
        if(checked[start]==-1) return false;
        if(checked[start]==1) return true; 
        
        checked[start]=-1;
        for(auto s:course[start]){
            if(dfs(s,checked)==false) return false;
        }
        checked[start]=1;
        return true;
    }
};