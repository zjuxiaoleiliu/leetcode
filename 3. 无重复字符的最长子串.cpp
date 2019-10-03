题目描述:

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

//动态规划，需要一个映射保存当前元素之前的字符最近的出现情况位置信息
//流式处理，需要边遍历边更新这个映射中保存的字符最近出现位置信息
//应用动态规划解决问题时关键的一点是得出递推公式，根据递推公式我们显然需要一个映射保存当前元素
//之前的字符最近的出现情况位置信息

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.length() == 0)
            return 0;
        if(s.length() == 1)
            return 1;
        unordered_map<char,int> m;//映射，保存的是下标，是位置信息
        int ret = 1;
        int last = 1;//以上一个字符结尾的最长的不重复子串长度
        m[s[0]]=0;
        for(int i = 1;i<s.length();i++)//流式处理，边处理边更新m中的信息
        {   
            if(m.find(s[i])==m.end() || m[s[i]]<i-last)
                last = last+1;
            else
                last = i-m[s[i]];
            if(last>ret)
                    ret = last;
            m[s[i]]=i;
        }
        return ret;        
    }
};



  