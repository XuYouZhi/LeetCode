/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size()<3) return points.size();
        int result=0;
        
        unordered_map<double, int> slope_count;
        for(int i=0;i<points.size();++i){
            slope_count.clear();
            int same_count=0; // 和i重合的点
            int point_max=1; // 和i共线的最大点数
            
            for(int j=0;j<points.size();++j){
                if(i==j) continue;
                double slope;
                if(points[i].x==points[j].x){
                    slope=std::numeric_limits<double>::infinity();
                    if(points[i].y==points[j].y){
                        ++same_count;
                        continue;
                    }
                }
                else{
                    slope=1.0*(points[i].y-points[j].y)/(points[i].x-points[j].x);
                }
                
                int count=0;
                if(slope_count.find(slope)!=slope_count.end()){
                    count=++slope_count[slope];
                }
                else{
                    count=2;
                    slope_count[slope]=2;
                }
                
                if(count>point_max) point_max=count;
            }
            
            result=max(result,point_max+same_count);
        }
        
        return result;
    }
};