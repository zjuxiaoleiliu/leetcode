题目描述:

Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
//解法1：中心扩展法，时间复杂度为o(n^2)
//由于暴力法时间复杂度为o(n^3),所以我们的第一个想法
//是看看能不能把复杂度从o(n^3)降下来，暴力法需要遍历子串
//的两个边界的所有情况，所以我们看看能不能把这个瓶颈降下来
//只通过一个点得到一个待判定的回文子串

class Solution {
public:
    string longestPalindrome(string s) {

    	if(s.length() == 0)
    		return "";
        if(s.length() == 1)
            return s.substr(0,1);
    	int left = 0;
    	int len = 1;
    	for(int i = 1;i<s.length();i++)
    	{
    		int curLeft = i;
    		int curLen = 1;
    		int j = 1;//奇数长度回文串中心向外扩展
            //i-j左边界，i+j右边界
    		while(i-j>=0 && i+j<=s.length()-1 && s[i-j]==s[i+j])
    		{
    			curLeft = i-j;
    			curLen = 2*j+1;
    			j++;   			
    		}
    		if(curLen>len)
    		{
    			len = curLen;
    			left = curLeft;
    		}
    		if(s[i-1] == s[i])//偶数长度回文串中心向外扩展
    		{
    			int curLeft = i-1;
    			int curLen = 2;
    			int j = 1;
    			while(i-1-j>=0 && i+j<=s.length()-1 && s[i-1-j]==s[i+j])
    			{
    				curLeft = i-1-j;
    			    curLen = 2*j+2;
    			    j++;
    			    
    			}
    			if(curLen>len)
    			{
    				len = curLen;
    			    left = curLeft;
    			}

    		}

    	}
    	return s.substr(left,len);       
    }
};

//方法2：动态规划解法,复杂度为o(n^2)，枚举所有的
//子串是否为回文串的判断情况，在这个过程中更新最大值
//流式处理，当新添加入一个元素时，要判断以这个新元素为
//右边界所能构成的回文串，我们需要知道这个新元素之前的子字符串
//各个子串能否构成回文串的情况，进而得出动态规划过程中我们需要
//保存的中间信息


class Solution {
public:
    string longestPalindrome(string s) {

    	int n = s.length();
    	if(n == 0)
    		return "";
        if(s.length() == 1)
            return s[0];
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        dp[0][0] = true;
        int left=0,len=1;
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<=i;++j)
            {                   //[i,j]中间有0个元素，有1个元素
                if(s[i]==s[j] && (i-j<2 || dp[j+1][i-1]==true))
                {
                    dp[j][i]=true;
                    if(i-j+1>len)
                    {
                        left=j;
                        len=i-j+1;
                    }
                }
            }
        }

        return s.substr(left,len);
    }
};