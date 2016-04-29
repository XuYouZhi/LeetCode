/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const Interval& a, const Interval& b)->bool{return a.start<b.start;});
        
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