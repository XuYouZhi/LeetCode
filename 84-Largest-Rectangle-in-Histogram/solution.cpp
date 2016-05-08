// // Not Work
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         if(heights.size()<1) return 0;
        
//         int len=1;
//         int min_height=heights[0];
//         int max_sum=0;
//         for(int i=1;i<heights.size();++i){
//             min_height=min(min_height,heights[i]);
//             if(min_height*(len+1)>max_sum){
//                 if(heights[i]>min_height*(len+1)){
//                     min_height=heights[i];
//                     max_sum=heights[i];
//                     len=1;
//                 }
//                 else{
//                     max_sum=min_height*(len+1);
//                     ++len;
//                 }
//             }
//             else{
//                 ++len;
//             }
//         }
        
//         return max_sum;
//     }
// };


// O(n) O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int result=0;
        
        for(int i=0;i<heights.size();){
            if(s.empty()||heights[i]>heights[s.top()]){
                s.push(i++);
            }
            else{
                int tmp=s.top();
                s.pop();
                result=max(result,heights[tmp]*(s.empty()?i:i-s.top()-1));
            }
        }
        
        return result;
    }
};
