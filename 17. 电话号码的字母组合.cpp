题目描述:

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

class Solution {
public:
    vector<string> letterCombinations(string digits) {
         
        vector<string> ret;
        if(digits.size()==0)
        	return ret;    
        vector<string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp;
        letterCombinationsCore(digits, dict, 0,ret,temp);
        return ret;
    }

    void letterCombinationsCore(string &digits, vector<string> &dict,int index,vector<string> &ret,string &temp) 
    {

    	if(index == digits.size())
    	{
    		ret.push_back(temp);
    		return;
    	}
        else
        {
        	string str = dict[digits[index] - '2'];
            for (int i = 0; i < str.size(); i++)
            {
                temp.push_back(str[i]);
                letterCombinationsCore(digits,dict,index+1,ret,temp);
                temp.pop_back();
            }
        }
         
    }
};