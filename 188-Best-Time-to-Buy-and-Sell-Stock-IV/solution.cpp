/*
参考链接：http://liangjiabin.com/blog/2015/04/leetcode-best-time-to-buy-and-sell-stock.html

用local[i][j]表示到达第i天时，最多进行j次交易的局部最优解；用global[i][j]表示到达第i天时，最多进行j次的全局最优解。它们二者的关系如下（其
中diff = prices[i] – prices[i – 1]）：

local[i][j] = max(global[i – 1][j – 1] , local[i – 1][j] + diff)
global[i][j] = max(global[i – 1][j], local[i][j])

local[i][j]和global[i][j]的区别是：local[i][j]意味着在第i天一定有交易（卖出）发生，当第i天的价格高于第i-1天（即diff > 
0）时，那么可以把这次交易（第i-1天买入第i天卖出）跟第i-1天的交易（卖出）合并为一次交易，即local[i][j]=local[i-1][j]
+diff；当第i天的价格不高于第i-1天（即diff<=0）时，那么local[i][j]=global[i-1][j-1]+diff，而由于diff<=0，所以可写成local[i][j]=global
[i-1][j-1]。

global[i][j]就是我们所求的前i天最多进行k次交易的最大收益，可分为两种情况：如果第i天没有交易（卖出），那么global[i][j]=global
[i-1][j]；如果第i天有交易（卖出），那么global[i][j]=local[i][j]。
*/

// 代码一 动态规划 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int n=prices.size();
        if(n<2) return 0;
        if(k>=n) return maxProfit_helper(prices);  // k大于天数时，其实就退化成 Best Time to Buy and Sell Stock II 了
        
        vector<vector<int>> local(n,vector<int>(k+1,0));
        vector<vector<int>> global(n,vector<int>(k+1,0));
        
        for(int i=1;i<n;++i){
            int diff=prices[i]-prices[i-1];
            for(int j=1;j<=k;++j){
                local[i][j]=max(global[i-1][j-1],local[i-1][j]+diff);
                global[i][j]=max(global[i-1][j],local[i][j]);
            }
        }
        
        return global[n-1][k];
    }
    
    
    int maxProfit_helper(vector<int>& prices){
        int result=0;
        
        for(int i=1;i<prices.size();++i){
            if(prices[i]>prices[i-1]){
                result+=prices[i]-prices[i-1];
            }
        }
        
        return result;
    }
};