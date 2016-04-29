/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
// // 方法一 边插边merge Time Limit Exceeded 
// class Solution {
// public:
//     vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
//         vector<Interval>::iterator it=intervals.begin();
        
//         while(it!=intervals.end()){ //[newInterval] [it]
//             if(newInterval.end<it->start){
//                 intervals.insert(it,newInterval);
//                 return intervals;
//             }
//             else if(newInterval.start>it->end){ // [it] [newInterval]
//                 ++it;
//                 continue;
//             }
//             else{ // [i [new  ]t  ]Interval
//                 newInterval.start=min(newInterval.start,it->start);
//                 newInterval.end=max(newInterval.end,it->end);
//                 it=intervals.erase(it);
//             }
//         }
        
//         intervals.insert(intervals.end(),newInterval); //合并到头了
//         return intervals;
//     }
// };


// 方法二 先插入再merge
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>::iterator it;
        for(it=intervals.begin();it!=intervals.end();++it){
            if(newInterval.start<it->start){
                break;
            }
        }
        intervals.insert(it,newInterval);
        
        return merge(intervals);
    }
    
    
    vector<Interval> merge(vector<Interval>& intervals) {
        //sort(intervals.begin(),intervals.end(),[](const Interval& a, const Interval& b)->bool{return a.start<b.start;});
        vector<Interval> result;
        
        if(intervals.size()<1) return result;
        
        Interval temp=intervals[0];
        for(int i=1;i<intervals.size();++i){
            if(temp.end>=intervals[i].start){
                temp.end=max(intervals[i].end,temp.end);
            }
            else{
                result.push_back(temp);
                temp=intervals[i];
            }
        }
        result.push_back(temp);
        
        return result;
    }
};

