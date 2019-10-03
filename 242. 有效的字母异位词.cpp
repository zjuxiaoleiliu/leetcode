给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

class Solution {
public:
    bool isAnagram(string s, string t) {

    	if(s.empty() && t.empty())
    		return true;
    	if(s.empty() || t.empty())
    		return false;
    	if(s.length()!=t.length())
    		return false;
    	int n = s.length();
    	int m[26] = {0};
    	for(int i = 0;i < n;i++)
    	{
    		m[s[i]-'a']++;
    		m[t[i]-'a']--;
    	}
    	for(int i = 0;i < 26;i++)
    	{
    		if(m[i]!=0)
    			return false;
    	}
    	return true;

    }
};