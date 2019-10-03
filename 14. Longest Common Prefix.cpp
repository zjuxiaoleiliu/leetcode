题目描述:

Write a function to find the longest common prefix string 
amongst an array of strings.

//直接的思路：有点暴力o(n^2)
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {

    	if(strs.size() == 0)
    		return "";
    	string ret = "";
    	for(int i = 0;i<strs[0].length();i++)
    	{
    		for(int j = 1;j<strs.size();j++)
    		{
    			if(i>=strs[j].length() || strs[j][i]!=strs[0][i])
    				return ret;
    		}
    		ret+=strs[0][i];
    	}
    	return ret;       
    }
};

//方法2：先对字符串排序，然后考虑第一个和最后一个的首字符，这两个字符必定是差距
//最大的两个(因为排序首先从第一个开始排)，如果这两个不等，就返回空，否则，
//说明所有字符串的首字符相等，那么接着判断第二个。

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {

        if(strs.size() == 0)
            return "";
        sort(strs.begin(),strs.end());         
        int n = strs.size();
        int len = min(strs[0].size(),strs[n-1].size());
        string ret = "";
        for(int i=0;i<len;i++)
        {
        	if(strs[0][i] != strs[n-1][i])
                return ret;
            else
            	ret+=strs[0][i];
        }
        
        return ret;
    }
};