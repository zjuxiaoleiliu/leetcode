题目描述:

Given a string s, partition s such that every substring of the partition 
is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s ="aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]



class Solution {
public:
    vector<vector<string>> partition(string s) {

    	vector<vector<string>>ret;
    	if(s.length() == 0)
    		return ret;
        vector<string> temp;
        partitionCore(s,0,ret,temp);
        return ret;
    }

    bool isPalindrome(string s){

    	int i = 0;
    	int j = s.length()-1;
    	while(i<j)
    	{
    		if(s[i]!=s[j])
    			return false;
    		else
    		{
    			i++;
    			j--;
    		}

    	}
    	return true;

    }
 
    void partitionCore(string &s,int start,vector<vector<string>> &ret,vector<string> &temp){

        if(start==s.size())
        {
            ret.push_back(temp);
            return;
        }        
        else
        {   //枚举当前步可以划分的回文子串情况
            //i为当前分割的子串的右端点下标
        	for(int i = start; i < s.length(); ++i) 
        	{   //枚举遍历第一步可以划分的所有情况
        		string sub=s.substr(start,i-start+1);
        		if(isPalindrome(sub))//前缀解释法
        		{
        			temp.push_back(sub);
        			partitionCore(s,i+1,ret,temp);
                    temp.pop_back();
                }
            }
        }
 
    }
 
};