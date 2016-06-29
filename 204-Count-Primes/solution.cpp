// 代码一 对每个数判断是否为质数（素数）
class Solution {
public:
    int countPrimes(int n) {
        int result=0;
        for(int i=1;i<n;++i){
            if(isPrime(i)){
                ++result;
            }
        }
        return result;
    }
    
    bool isPrime(int num){
        if(num<=1) return false;
        
        for(int i=2;i*i<=num;++i){
            if(num%i==0) return false;
        }
        
        return true;
    }
};


// // 代码二 筛素数法
// class Solution {
// public:
//     int countPrimes(int n) {
//         vector<bool> isprime(n,true);
//         isprime[0]=isprime[1]=false;
        
//         for(int i=2;i*i<=n;++i){
//             if(isprime[i]==false) continue;
//             for(int j=i*i;j<n;j+=i){
//                 isprime[j]=false;
//             }
//         }
        
        
//         int result=0;
//         for(int i=0;i<n;++i){
//             if(isprime[i]){
//                 ++result;
//             }
//         }
        
//         return result;
//     }
// };