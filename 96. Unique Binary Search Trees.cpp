题目描述:

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

//递归方法，这个解法Leecode会超时
class Solution {
public:
    int numTrees(int n) {

    	if(n == 0)
    		return 1;
    	int cnt = 0;
    	for(int i = 1;i <= n;i++)//遍历根节点元素所有可能的情况
    	{
    		cnt+=numTrees(i-1)*numTrees(n-i);
   
    	}
    	return cnt;        
    }
};

//将上面的递归方法翻译成动态规划
class Solution {
public:
    int numTrees(int n) {

        if(n == 0)
            return 1;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= i;j++)//遍历根节点元素所有可能的情况
            {
                dp[i]+=dp[j-1]*dp[i-j];
       
            }
        }
        return dp[n];        
    }
};