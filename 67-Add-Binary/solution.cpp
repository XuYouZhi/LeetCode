class Solution {
public:
    string addBinary(string a, string b) {
        const int n=max(a.size(),b.size());
        string result;
        
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        int carry=0;
        for(int i=0;i<n;++i){
            const int ai=i<a.size()?a[i]-'0':0;
            const int bi=i<b.size()?b[i]-'0':0;
            const int val=(ai+bi+carry)%2;
            carry=(ai+bi+carry)/2;
            
            result.insert(result.begin(),val+'0');
        }
        
        if(carry>0){
            result.insert(result.begin(),carry+'0');
        }
        
        return result;
    }
};