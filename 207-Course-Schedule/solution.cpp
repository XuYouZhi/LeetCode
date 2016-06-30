// // 代码一  DFS
// /*
// 思路：先建立好有向图，然后从第一个门课开始，找其前驱课程，暂时将当前课程标记为已访问，然后对新得到的课程调用DFS递归，直到出现新的课程       已经访问过了（有向图有环），则返回false，没有冲突的话（无环）返回true，然后把标记当前课程无冲突（无环，如果一个课程的前驱课程为该课   程，直接返回无冲突）
// */
// class Solution {
// private:
//     unordered_map<int,vector<int>> course;
    
// public:
//     bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
//         for(int i=0;i<prerequisites.size();++i){
//             int first=prerequisites[i].first, second=prerequisites[i].second;
//             if(course.find(first)==course.end()){
//                 course[first]=vector<int>();
//             }
//             course[first].push_back(second);
//         }
        
//         unordered_map<int,vector<int>>::iterator iter;
//         unordered_map<int,int> checked;
//         for(iter=course.begin();iter!=course.end();++iter){
//             checked[(*iter).first]=0;
//         }
        
//         for(iter=course.begin();iter!=course.end();++iter){
//             int start=(*iter).first;
//             if(dfs(start, checked)==false) return false;
//         }
        
//         return true;
//     }
    
//     bool dfs(int start, unordered_map<int,int> &checked){
//         if(checked[start]==-1) return false;
//         if(checked[start]==1) return true; 
        
//         checked[start]=-1;
//         for(auto s:course[start]){
//             if(dfs(s,checked)==false) return false;
//         }
//         checked[start]=1;
//         return true;
//     }
// };



// 代码二 BFS
/*
思路：定义二维数组graph来表示这个有向图，一位数组in来表示每个顶点的入度。我们开始先根据输入来建立这个有向图，并将入度数组也初始化好。然后   我们定义一个queue变量，将所有入度为0的点放入队列中，然后开始遍历队列，从graph里遍历其连接的点，每到达一个新节点，将其入度减一，如果   此时该点入度为0，则放入队列末尾。直到遍历完队列中所有的值，若此时还有节点的入度不为0，则说明环存在，返回false，反之则返回true。
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses,0);
        
        for(auto a:prerequisites){
            graph[a.second].push_back(a.first);
            ++in[a.first];
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;++i){
            if(in[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int t=q.front();
            q.pop();
            
            for(auto a:graph[t]){
                --in[a];
                if(in[a]==0) q.push(a);
            }
        }
        
        for(int i=0;i<numCourses;++i){
            if(in[i]!=0) return false;
        }
        
        return true;
    }
};