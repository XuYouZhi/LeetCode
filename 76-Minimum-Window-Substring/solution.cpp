// 使用双指针，动态维护一个区间。尾指针不断往后扫，当扫到一个窗口完整的包含T所有字符后，然后收缩头指针直到不能收缩，更新计量长度。
// O(n) O(1)
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty()) return "";
        if(s.size()<t.size()) return "";
        
        const int ASCII_MAX=256;
        int appeared_count[ASCII_MAX];
        int expected_count[ASCII_MAX];
        fill(appeared_count,appeared_count+ASCII_MAX,0);
        fill(expected_count,expected_count+ASCII_MAX,0);
        
        for(int i=0;i<t.size();++i) expected_count[t[i]]++;
        
        int min_width=INT_MAX, min_start=0;
        int wstart=0;
        int appeared=0;
        //尾指针不断往后扫
        for(int wend=0;wend<s.size();++wend){
            if(expected_count[s[wend]]>0){ //如果字母为t中的一部分
                appeared_count[s[wend]]++;
                if(appeared_count[s[wend]]<=expected_count[s[wend]]){
                    ++appeared;
                }
            }
            
            //包含了完整的T
            if(appeared==t.size()){
                //开始收缩头指针,直到不能在缩
                while(appeared_count[s[wstart]]>expected_count[s[wstart]]||expected_count[s[wstart]]==0){
                    appeared_count[s[wstart]]--;
                    ++wstart;
                }
                
                if(wend-wstart+1<min_width){
                    min_width=wend-wstart+1;
                    min_start=wstart;
                }
            }
        }
        
        if(min_width==INT_MAX) return "";
        else return s.substr(min_start,min_width);
    }
};