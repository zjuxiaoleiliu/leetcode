给定不同面额的硬币 coins 和一个总金额 amount。
编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1
说明:
你可以认为每种硬币的数量是无限的。


//动态规划,分解，递推公式
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0)
        	return 0;
    	int n = coins.size();
    	if(n == 0)
    		return -1;
    	vector<int> dp(amount+1,INT_MAX);
    	dp[0] = 0;
    	for(int i = 1;i <= amount;i++)
    	{
    		for(int j = 0;j < n;j++)
    		{
    			if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX)
    				dp[i] = min(dp[i],dp[i-coins[j]]+1);
    		}
    	}
    	return dp[amount]==INT_MAX?-1:dp[amount];        
    }
};