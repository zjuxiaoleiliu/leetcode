
Given a non-empty string s and a dictionary wordDict containing 
a list of non-empty words, add spaces in s to construct a sentence 
where each word is a valid dictionary word. 
Return all such possible sentences.

Note:
The same word in the dictionary may be reused multiple times 
in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]


//递归版本：为了防止重复计算，使用了一个映射保存中间结果
//LeetCode耗时20ms,内存消耗12MB
class Solution {
public:
    vector<string> wordBreak(string s, vector<string> wordDict) {

        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        int n=s.length();
        int minLen = n;
        int maxLen = 0;       
        for(auto word:dict)
        {
            int temp = word.length();
            minLen = min(minLen,temp);
            maxLen = max(maxLen,temp);
        }
        unordered_map<string,vector<string>> m;
        return wordBreakCore(dict,minLen,maxLen,s,m);       
    }

    vector<string> wordBreakCore(unordered_set<string> &dict,int minLen,int maxLen,string s,unordered_map<string,vector<string>> &m)
    {
        if(m.find(s)!=m.end())
            return m[s];
        vector<string> ret;
        // 不分割
        if(dict.find(s)!=dict.end())
            ret.push_back(s);
        
        // 分割        
        for(int l = minLen; l<s.length() && l<=maxLen; l++)
        {
            string left = s.substr(0,l);
            if(dict.find(left)!=dict.end())
            {
               vector<string> right = wordBreakCore(dict,minLen,maxLen,s.substr(l),m);
                // 可以成功分割
               if(right.size() > 0)
               {
                   for(auto str : right){
                       ret.push_back(left+" "+str);
                   }
               } 
            }
        }
        m[s] = ret;        
        return ret;
    }
};

//思路：DFS+利用动态规划得到的信息剪枝
//leetcode耗时12ms,内存消耗9.8MB
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        int n=s.length();
        vector<bool> dp(n+1,false);
        dp[n] = true;//要合理的初始化使之满足递推公式的要求
        int minLen = n;
        int maxLen = 0;       
        for(auto word:dict)
        {
            int temp = word.length();
            minLen = min(minLen,temp);
            maxLen = max(maxLen,temp);
        }       //i+minLen==n
        for(int i=n-minLen;i>=0;i--)
        {
            for(int l=minLen;l<=maxLen && l<=n-i;l++)
            {
                if(dict.find(s.substr(i,l))!=dict.end() && dp[i+l])
                {
                  dp[i] = true;
                  break;
                }
            }
        }
        vector<string> ret;
        if(dp[0] == false)
            return ret;
        dfs(dict,minLen,maxLen,dp,s,0,"",ret);
        return ret;
    }

    void dfs(unordered_set<string> &dict, int minLen, int maxLen,vector<bool> &dp, string &s, int index,string cur,vector<string> &ret)
    {
        for(int l = minLen; l<=maxLen && l<=s.size()-index;l++)
        {
            if(dict.find(s.substr(index,l))!=dict.end() && dp[index+l]) 
            {
                if(index+l == s.size())//最后一个单词的情况 
                    ret.push_back(cur+s.substr(index,l));
                else//注意这里的拼接技巧,还不到最后一个单词的话，每一个单词后面加" ",遇到最后一个单词,只拼接单词,不加" "
                    dfs(dict,minLen,maxLen,dp,s, index+l,cur+s.substr(index,l)+" ",ret);
            }
        }
    }
};



