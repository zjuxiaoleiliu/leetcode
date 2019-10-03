题目描述:

给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由words中
所有单词串联形成的子串的起始位置。注意子串要与 words 中的单词完全匹配，
中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
示例 1：

输入：
  s = "barfoothefoobarman",
  words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
示例 2：

输入：
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
输出：[]

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ret;
    	if(s.length()==0 || words.size()==0)
    		return ret;        
        unordered_map<string,int>m;
        for(auto word:words)//映射的初始化
        {
        	if(m.find(word) == m.end())
        		m[word]=1;
        	else
        		m[word]++;
        }
        int n = s.length();
        int size = words.size();
        int len = words[0].size();
        for(int i = 0; i<=n-size*len; i++)//遍历所有可能的起点进行判断 
        {            
            unordered_map<string,int> temp;
            int j = i;
            for(; j<i+size*len; j+=len) 
            {
                string word = s.substr(j, len);
                if(m.find(word) != m.end())
                {
                	if(temp.find(word) == temp.end())
                		temp[word]=1;
                	else
                		temp[word]++;
                    if(temp[word] > m[word])//如果此单词出现次数超出，则i位置不合法
                    	break;
                }
                else break;
            }

            if(j==i+size*len)
                ret.push_back(i);
        }

        return ret;
    }

};





/*
使用在 s 上的滑动窗口来匹配 words 数组，双指针 left，right 分别表示窗口的开始和结束。
指针移动的单位长度为 words 数组中单词的长度，假设为 l。
每次取 s 上 right 到 right+l 的一个新单词加入窗口。
假设这个单词不在 words 数组中（借助 HashMap 判断），
说明这个窗口不合格，就将 right 置为 right+l，left 置为 right，继续找。
假设这个单词在 words 数组中，但在窗口中的出现次数大于在 words 数组中的出现次数，
说明这个窗口还是不合格，需要不断的将 left 加上 l，即不断的删除窗口最左边的单词，
直到这个单词在窗口中的出现次数与在 words 数组中的出现次数相等为止。
否则就表示当前窗口的所有单词都在 words 数组中，窗口没有任何问题，
right 加上 l 继续向右取新的单词。
当窗口长度 right-left 正好为 words 数组中所有单词的长度和时，
就表示匹配成功，将 left 加入结果集。


*/

class Solution {

  public List<Integer> findSubstring(String s, String[] words) {

    List<Integer> result = new ArrayList<>();
    if(s.length() == 0 || words.length == 0) 
        return result;
    HashMap<String, Integer> wordsCount = new HashMap<>();
    for(String word : words)
    { 
        // 将所有单词加入 HashMap，并计数
        if(wordsCount.containsKey(word)) 
            wordsCount.put(word, wordsCount.get(word)+1);
        else 
            wordsCount.put(word, 1);
    }
    int length = words[0].length();
    for(int i = 0; i < length; ++i)
    {   // 错位循环，保证每种情况都遍历到
        HashMap<String, Integer> window = new HashMap<>();
        int left = i;
        int right = i;
        while(right <= s.length()-length && left <= s.length()-length*words.length)
        {
            String subRight = s.substring(right, right + length);
            // 如果这个单词不在 words 中，就重置窗口
            if(!wordsCount.containsKey(subRight))
            {
                window.clear();
                right += length;
                left = right;
                continue;
            }
            // 将刚进入窗口并在 words 中的单词加入窗口 Hash 表
            if(window.containsKey(subRight)) 
                window.put(subRight, window.get(subRight)+1);
            else 
                window.put(subRight, 1);
            // 当该单词在窗口中的出现次数多于在 words 中的出现次数时，
            //不断删除窗口中最左边单词，直到次数相等
            while(window.get(subRight) > wordsCount.get(subRight))
            {
                String subLeft = s.substring(left, left + length);
                if(window.get(subLeft) == 1) 
                    window.remove(subLeft);
                else 
                    window.put(subLeft, window.get(subLeft)-1);
                left += length;
            }
            right += length;
            // 当窗口长度正好等于 words 总长度时，表示匹配成功，加入结果中
            if(right-left == length*words.length) result.add(left);
        }
    }
    return result;
}


    
}