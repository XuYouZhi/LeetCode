// // 代码一 Time Limit Exceeded  O(n^2)  O(1)
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         for(int i=0;i<gas.size();++i){
//             if(canCompleted(i,gas,cost)){
//                 return i;
//             }
//         }
        
//         return -1;
//     }
    
    
// private:
//     bool canCompleted(int start, vector<int>& gas, vector<int>& cost){
//         const int n=gas.size();
//         int sum=0;
//         for(int i=0;i<n;++i){
//             int idx=(start+i)%n;
//             sum+=(gas[idx]-cost[idx]);
//             if(sum<0) return false;
//         }
        
//         return true;
//     }
// };


// // 代码二 Time Limit Exceeded O(n^2) O(n)
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         const int n=gas.size();
//         vector<int> gap=vector<int>(n,0);
//         for(int i=0;i<n;++i){
//             gap[i]=gas[i]-cost[i];
//         }
        
//         for(int i=0;i<gas.size();++i){
//             if(canCompleted(i,gap)){
//                 return i;
//             }
//         }
        
//         return -1;
//     }
    
// private:
//     bool canCompleted(int start, vector<int>& gap){
//         const int n=gap.size();
        
//         int sum=0;
//         for(int i=0;i<n;++i){
//             int idx=(start+i)%n;
//             sum+=gap[idx];
//             if(sum<0) return false;
//         }
        
//         return true;
//     }
// };


// 代码三 O(n) O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        int j=-1;
        for(int i=0,sum=0;i<gas.size();++i){
            sum+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            
            if(sum<0){
                j=i;
                sum=0;
            }
        }
        
        return total>=0?j+1:-1;
    }
};