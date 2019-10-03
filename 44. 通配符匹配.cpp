题目描述:
          //Linux命令行*.txt    通配符
Implement wildcard(通配符) pattern matching 
with support for'?'and'*'.

'?' Matches any single character.(这里应该是非空字符)
'*' Matches any sequence of characters
(including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:

bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

//方法1：常规思路,动态规划
//必须都得用掉
class Solution {
public:
    bool isMatch(const char *s, const char *p) {

        int m = strlen(s);
        int n = strlen(p);
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));        
        dp[0][0] = true;        
        for(int i=1; i<=n; i++)
        {
        	if(p[i-1] == '*')//匹配空串
        		dp[0][i] = dp[0][i-1];           
        } //根据我们的初始化dp时的情况,天然的dp[i][0]=false,1<=i<=m       
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(p[j-1]==s[i-1] || p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];               
                else if(p[j-1] == '*')//'*'如何匹配使用,不同的状态转移机
                	     //'*'匹配一个空串    '*'这里匹配一个串，串的末尾为s[i-1]  
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];//即'*'匹配为'*s[i-1]'
            }
        }        
        return dp[m][n]; 
    }
};


/*
主要是'*'的匹配处理。遇到'*'就跳过去，
优先用'*'后面的来匹配。如果'*'后面的匹配不上，
则用'*'匹配一个字符，再看'*'后面的能否匹配上。。。。。
*/
//不匹配时往最近的*回溯
class Solution {
public:
    bool isMatch(string s, string p) {
        
        int m = s.length();
        int n = p.length();
        if(m==0 && n==0)
        	return true;
        if(m!=0 && n==0)
        	return false;
    	int i = 0;
	    int j = 0;
	    int last = -1;//p中最近出现的'*'的下标
	    int lastStart = 0;//最近的一次对'*'的匹配做出的处理后i开始要匹配的下标
	    while(i < m) 
	    {
	    	if(j<n && (p[j] == '?' || p[j]==s[i])) 
	    	{
	    		++i;
			    ++j;
		    }             //*按照匹配0个，1个，2个，。。。的顺序使用
		    else if(j<n && p[j]=='*')//由于这是遇到的新的*，初次匹配空串，优先使用后面的 
		    {
		    	last = j;		
			    lastStart = i;
			    j++;
		    } 
		    else if(last != -1)//可以对应着思考使用动态规划时 
		    {                 //的递推公式中的状态转移方程式
		    	j = last + 1;
			    i = lastStart+1;
			    lastStart = i;
		    } 
		    else
		    	return false;
		}
	    while(j<n && p[j]=='*') ++j;
	    return j == n;
    }
};
