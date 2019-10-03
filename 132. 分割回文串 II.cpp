题目描述:

给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
返回符合要求的最少分割次数。

示例:

输入: "aab"
输出: 1
解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

//暴力动态规划
//LeetCode耗时40ms,内存消耗9.3MB
class Solution {
public:
	int minCut(string s)
    {   
    	int n = s.length();
    	if(n == 0 || n == 1)
    		return 0;
        vector<int> dp(n);
        for(int i=0;i<n;i++)
           dp[i] = i;
        vector<vector<bool>> isPalindrome(n,vector<bool>(n,false));
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j <= i;j++)
            {
                if(s[j] == s[i] && (i-j<2 || isPalindrome[j+1][i-1]))
                {
                	isPalindrome[j][i] = true;
                	if(j == 0)
                		dp[i]=0;
                    else 
                    	dp[i] = min(dp[i],1+dp[j-1]);
                }   
            }
        }
        return dp[n-1];
    }
};

//中心扩展法更新dp的值
class Solution {
public:
    int minCut(string s) {

        int n = s.size();//dp[i]含义为s[0,i-1]的最小分割次数
        vector<int> dp(n+1, 0);
        for(int i = 0; i <= n; i++) 
            dp[i] = i-1;//这里根据递推公式合理的将dp[0]初始化为-1
        //根据我们的操作过程，我们枚举了所有的中心扩展情况，i左边的dp都已经更新是确定的值了
        //所以1+dp[i-j]是对s[0:i+j+1)的一次合理的分割，
        //关键的一点是这个操作过程可以对dp的值的更新做到不遗漏，
        //每一次的计算得到的值都是一个合法的值(因为i左边的dp值已经是最后的值了)
        for(int i = 0; i < n; i++)//i为元素下标
        {      //j为相对于i的偏移量
            for(int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // 奇数 length palindrome
                dp[i+j+1] = min(dp[i+j+1],1+dp[i-j]);
            for(int j = 0; i-j >= 0 && i+1+j < n && s[i-j] == s[i+1+j]; j++) // 偶数 length palindrome
                dp[i+1+j+1] = min(dp[i+1+j+1],1+dp[i-j]);
        }
        return dp[n];
    }
};




