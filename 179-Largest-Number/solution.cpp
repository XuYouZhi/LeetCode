class Solution {
public:
    static bool comp(const string& s1, const string& s2){
        //return s1>s2; // wrong 121 12
        return s1+s2>s2+s1;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        for(int i=0;i<nums.size();++i){
            vs.push_back(to_string(nums[i]));
        }
        
        sort(vs.begin(),vs.end(),comp);
        
        string result="";
        
        for(int i=0;i<vs.size();++i){
            result+=vs[i];
        }
        
        if(result[0]=='0') return "0"; // [0,0]的情况
        
        return result;
    }
};