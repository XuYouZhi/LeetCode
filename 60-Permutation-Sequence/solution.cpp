// 方法一 康托编码  K=a1(n-1)!+a2(n-2)!+...,an(0)! ， 如小于321的排列数有2[小于3的数有2个]*2[n-1]!+1[小于2的数有1个]*1[n-2]!=5个,所有321为第6个排列
class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n,'0');
        for(int i=0;i<n;++i){
            s[i]+=i+1;
        }
        
        return kthPermutation(s,k);
    }
    
    int factorial(int n){
        int result=1;
        for(int i=1;i<=n;++i){
            result*=i;
        }
        return result;
    }
    
    string kthPermutation(string& s, int k){
        const int n=s.size();
        string result;
        
        int base=factorial(n-1);
        --k;
        
        for(int i=n-1;i>0;k%=base,base/=i,--i){
            auto a=next(s.begin(),k/base);
            result.push_back(*a);
            s.erase(a);
        }
        
        result.push_back(s[0]);
        return result;
    }
    
};