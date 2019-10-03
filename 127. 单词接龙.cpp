题目描述:

给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的
最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。


//宽度优先遍历
class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) 
    {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.find(end) == dict.end()) 
            return 0;
        queue<string> q;
        q.push(start);
        int ret=0;
        while(!q.empty())
        {
            ret++;
            int size=q.size();//先得到这一层到底有多少个节点
            //一个循环一次性处理这一层的全部节点
            while(size--)//从size到1，循环共进行了size次
            {
                string word=q.front();
                q.pop();
                if(canTransformed(word, end))
                    return ret+1;
                for(int i = 0; i < word.size(); ++i) 
                {
                    string next = word;
                    for(char c = 'a'; c <= 'z'; ++c) 
                    {
                        next[i] = c;
                        if(dict.find(next)!=dict.end())
                        {
                            //if(next == end)
                                //return ret+1;
                            q.push(next);
                            dict.erase(next);           
                        } 
                    }
                }        
            }
        }
        return 0;
    } 
     
    bool canTransformed(const string &s,const string &str)
    {
        int cnt=0;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]!=str[i])
                ++cnt;
        }
        return (cnt==1)?true:false;
    }
    
};