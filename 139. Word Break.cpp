题目描述:

Given a string s and a dictionary of words dict, 
determine if s can be segmented into a space-separated 
sequence of one or more dictionary words.

For example, given
s ="leetcode",
dict =["leet", "code"].

Return true because"leetcode"can be segmented as"leet code".

//动态规划
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
    	
        if(dict.find(s)!=dict.end())
        	return true;
        int n=s.length();
        vector<bool> dp(n+1,false);
        dp[0] = true;//要合理的初始化使之满足递推公式的要求
        for(int i=1;i<=n;i++)
         {
            for(int j=0;j<i;j++)
            {
                if(dp[j] && dict.find(s.substr(j,i-j))!=dict.end())
                {
                  dp[i] = true;
                  break;
                }
            }
        }
        return dp[n];
    }
};

//对上面代码的优化：字典中的单词的长度是有限度的，不必穷举所以的长度

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        
        if(dict.find(s)!=dict.end())
            return true;
        int n=s.length();
        vector<bool> dp(n+1,false);
        dp[0] = true;//要合理的初始化使之满足递推公式的要求
        int minLen = n;
        int maxLen = 0;
        for(auto word:dict)
        {
            int temp = word.length();
            minLen = min(minLen,temp);
            maxLen = max(maxLen,temp);
        }
        for(int i=1;i<=n;i++)
         {
            for(int l=minLen;l<=maxLen && l<=i;l++)
            {
                if(dict.find(s.substr(i-l,l))!=dict.end() && dp[i-l])
                {
                  dp[i] = true;
                  break;
                }
            }
        }
        return dp[n];
    }
};