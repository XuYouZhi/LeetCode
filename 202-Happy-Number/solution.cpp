class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> repeated;
        
        int nxt=next(n);
        while(nxt!=1&&repeated.find(nxt)==repeated.end()){
            repeated.insert(nxt);
            nxt=next(nxt);
        }
        
        return nxt==1;
    }
    
    int next(int n){
        int result=0;
        
        while(n){
            int r=n%10;
            n/=10;
            result+=r*r;
        }
        
        return result;
    }
};