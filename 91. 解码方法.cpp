题目描述:

A message containing letters from A-Z is being encoded to numbers using the following mapping:

A -> 1
B -> 2
...
Z -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message"12", it could be decoded as"AB"(1 2) or"L"(12).

The number of ways decoding"12"is 2.

//解法1：需要使用内存的动态规划循环解决方案
class Solution {
public:
    int numDecodings(string s) 
    {
    	if(s.length()==0 || s[0] == '0')
    		return 0;
        int length = s.length();
        vector<int> dp(length+1,0);
        dp[0]= 1;
        dp[1] = 1;//合理的初始化，符合递推公式的需要
        for(int len=2;len<=length;len++)
        {
            if(s[len-1]>='1' && s[len-1]<='9')//当前位不是数字0时才能自己单独解码
                dp[len] += dp[len-1];
            if(s[len-2]=='1' || (s[len-2]=='2' && s[len-1]>='0' && s[len-1]<='6'))
                dp[len] += dp[len-2];
        }
        return dp[length];
    }
};

//解法2：不使用辅助内存的，根据递推公式使用两个辅助变量的动态规划循环解决方案
class Solution {
public:
    int numDecodings(string s) 
    {
    	if(s.length()==0 || s[0] == '0')
    		return 0;
        int length = s.length();
        int pre = 1;
        int cur = 1;
        for(int len=2;len<=length;len++)
        {   
        	int temp = 0;
            if(s[len-1]>='1' && s[len-1]<='9')
                temp += cur;
            if(s[len-2]=='1' || (s[len-2]=='2' && s[len-1]>='0' && s[len-1]<='6'))
                temp += pre;
            pre = cur;
            cur = temp;
        }
        return cur;
       
    }
};


