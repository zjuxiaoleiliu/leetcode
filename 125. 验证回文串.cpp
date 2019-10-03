题目描述:

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

//两个指针法，从两边向中间逼近，如果沿途有数字字母类型，则绝对不会跳过


class Solution {
public:
    bool isPalindrome(string s) {

    	if(s.length() == 0)
    		return true;
    	int i = 0;
    	int j = s.length()-1;
    	while(i < j)
    	{
    		while(i < j && !isalnum(s[i])) i++;//遇到字母和数字就要停下来，等待
            if(i >= j)                         //这个位置的匹配
                return true;
    		while(i < j && !isalnum(s[j])) j--;
            if(i >= j)
                return true;
    		else
    		{
    			if(s[i]==s[j] || tolower(s[i])==tolower(s[j]))
    			{
    				i++;
    				j--;
    			}
    			else
    				return false;
    		}
    	}
    	return true;      
    }
};



