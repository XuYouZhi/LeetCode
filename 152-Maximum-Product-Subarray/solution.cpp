struct MinMax{
    int mi;
    int ma;
    MinMax(int _mi, int _ma):mi(_mi),ma(_ma){};
    MinMax(){mi=INT_MAX;ma=INT_MIN;};
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n=nums.size();
        vector<MinMax> f(n);
        
        for(int i=0;i<n;++i){
            f[i].mi=f[i].ma=nums[i];
        }
        
        for(int i=1;i<n;++i){
            int a=nums[i], b=f[i-1].mi*a, c=f[i-1].ma*a;
            f[i].mi=min(min(a,b),c);
            f[i].ma=max(max(a,b),c);
        }
        
        int result=INT_MIN;
        for(int i=0;i<n;++i){
            if(f[i].ma>result){
                result=f[i].ma;
            }
        }
        
        return result;
    }
};