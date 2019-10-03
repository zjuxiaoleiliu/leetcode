实现 strStr() 函数。
给定一个 haystack 字符串和一个 needle 字符串，
在 haystack 字符串中找出 needle 字符串出现的第一个位置 
(从0开始)。如果不存在，则返回  -1。
示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？
这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。
这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

//暴力法
class Solution {
public:
    int strStr(string haystack, string needle) {

    	int len1 = haystack.length();
    	int len2 = needle.length();
    	if(len2 == 0)
    		return 0;
    	if(len1 == 0 || len1 < len2)
    		return -1;
    	for(int i = 0;i <= len1-len2;i++)
    	{
    		string sub = haystack.substr(i,len2);
    		if(sub == needle)
    			return i;
    	}
    	return -1;        
    }
};

//KMP算法
class Solution {
public:
    int strStr(string str, string pattern) {

    	int n = str.length();
    	int m = pattern.length();
    	if(m == 0)
    		return 0;
    	if(n == 0 || n < m)
    		return -1;
    	vector<int> match(m,-1);
    	BuildMatch(pattern, match); 
    	int s = 0;
    	int p = 0; 
		while(s < n && p < m) 
		{
			if(str[s]==pattern[p]) 
			{
				s++; 
				p++;
			}    
			else if(p > 0) 
				p = match[p-1]+1;
			else 
				s++;
		}     
		return (p==m)?(s-m) : -1;     
    }
    
    void BuildMatch(string &pattern, vector<int> &match)
	{
		int m = pattern.length();
		match[0] = -1;
		for(int j = 1; j < m; j++) 
		{
			int i = match[j-1];
			while((i>=0) && (pattern[i+1]!=pattern[j])) i = match[i];
			if(pattern[i+1]==pattern[j])
				match[j] = i+1;
			else 
				match[j] = -1;
		}
	}

};


 