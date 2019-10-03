题目描述:

Given two words (beginWord and endWord), and a dictionarys word list, 
find all shortest transformation sequence(s) from beginWord to endWord,
such that:
Only one letter can be changed at a time
Each transformed word must exist in the word list.

Note that beginWord is not a transformed word.
Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]

Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore 
no possible transformation.


/*
For the most voted solution, it is very complicated.
I do a BFS for each path
for example:
{hit} ->
{hit,hot} ->
{hit,hot,dot}/{hit,hot,lot} ->
["hit","hot","dot","dog"]/["hit","hot","lot","log"] ->
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
         
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.find(endWord) == dict.end()) 
            return {};
        vector<vector<string>> ret;
        queue<vector<string>> q;
        q.push({beginWord});
        dict.erase(beginWord);
        unordered_set<string> visited;
        bool success= false;
        while(!q.empty())
        {
            int n= q.size();
            while(n--)
            {   
                vector<string> cur = q.front();
                q.pop();
                string word = cur.back();
                if(canTransformed(word, endWord))
                {
                	cur.push_back(endWord);  
                    success=true;
                    ret.push_back(cur);
                }
                else
                {
                	if(success)
                		continue;
                    for(int i = 0; i < word.size(); ++i) 
                    {
                    	string next = word;
                        for(char c = 'a'; c <= 'z'; ++c) 
                        {
                        	next[i] = c;
                            if(dict.find(next)!=dict.end())
                            {
                            	visited.insert(next);
                                vector<string> temp = cur;
                                temp.push_back(next);
                                q.push(temp);           
                            } 
                        } 
                    }                    
                }
            }
            if(success) 
            	break;  
            for(auto elem:visited)
                dict.erase(elem); 
            visited.clear();
        }
        return ret;
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

/*
解法：传统的BFS+DFS
为了使每一层加入的结点唯一，并且在加入结点过程中获得层与层之间的
结点邻接关系，维护一个已经加入的结点所处于的层的信息，每加入一层的
结点，更新层与层之间的邻接关系表，(curNode,nextNodeList)

*/
class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
	{
		unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.find(endWord) == dict.end()) 
            return {};
        unordered_map<string, vector<string>> nextNodeList;
        unordered_map<string,int> level;//已经遍历到的结点所处于的层次
		queue<string> q;
		q.push(beginWord);
	    level[beginWord] = 1;
		bool success = false;
		while(!q.empty())
		{
			int n = q.size();
			while(n--)
			{
				string cur = q.front();
			    q.pop();
			    for(int i = 0; i < cur.size(); i++)
			    {
			    	string next = cur;
				    for(char c = 'a'; c <= 'z'; c++)
				    {
				    	next[i] = c;
					    if(dict.find(next) != dict.end())
					    {   //产生的下一层的新的结点
					    	if(level.find(next) == level.end())
						    {
						    	if(next == endWord)
						    		success = true;
						    	q.push(next);
							    level[next] = level[cur] + 1;
							    nextNodeList[cur].push_back(next);
						    }
						    else if(level[next] == level[cur]+1)
						    	nextNodeList[cur].push_back(next);  
					    }
				    }
				}
			}
			if(success)
				break;
		}

		if(!success)
        	return {};
        vector<vector<string>> ret;
        vector<string> temp;
        temp.push_back(beginWord);
        dfs(nextNodeList,beginWord,endWord,ret,temp);        
        return ret;
	}

	void dfs(unordered_map<string, vector<string>> &nextNodeList,string beginWord,string endWord,vector<vector<string>> &ret,vector<string> &temp)
    {
        if(beginWord == endWord)
        {
            ret.push_back(temp);
            return;
        }
        for(auto item : nextNodeList[beginWord]) 
        {
            temp.push_back(item);
            dfs(nextNodeList,item,endWord,ret,temp);
            temp.pop_back();
        }
    }
};

/*
两端同时dfs
在两端dfs的过程中，建立结点之间的邻接连接关系，保存在映射backtrace中
映射backtrace中的元素为:(curNode,nextNodeList)
如果存在解的话，最后再根据得到的结点之间的邻接联系关系，从开始单词开始
从前向后深度优先遍历到结束单词
*/
class Solution {   
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
    	
    	unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.find(endWord) == dict.end()) 
            return {};
        unordered_map<string, unordered_set<string>> nextNodeList;
               //保存正向BFS时当前层的所有唯一结点
        unordered_set<string> head({beginWord});
              //保存反向BFS时当前层的所有唯一结点
        unordered_set<string> tail({endWord});
        // if the current head is the starting head, reverse is false, otherwise true
        bool reverse = false;
        bool success = false;
        dict.erase(beginWord); 
        dict.erase(endWord);
        while(!finish && !head.empty() && !tail.empty())
        {
            // two-end bfs : swap head and tail to reach balance of two sets for optimized performance
            if(head.size() > tail.size()) 
            {
                reverse = !reverse;
                swap(head, tail);
            }
            unordered_set<string> nextLevel;
            for (auto item : head)
            {
                for (int l = 0; l < item.size(); ++l) 
                {
                	auto next = item;
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        next[l] = c;
                        if(tail.find(next) != tail.end()) 
                        {
                            if(!reverse) 
                            	nextNodeList[item].insert(next);
                            else 
                            	nextNodeList[next].insert(item);
                            success = true;
                        }
                        else if(dict.find(next) != dict.end())
                        {
                            nextLevel.insert(next);
                            if(!reverse) 
                            	nextNodeList[item].insert(next);
                            else 
                            	nextNodeList[next].insert(item);
                        }
                    }
                }
            }
            for(auto item : nextLevel)
                dict.erase(item); 
            head = nextLevel;
        } 

        if(!success)
        	return {};
        vector<vector<string>> ret;
        vector<string> temp;
        temp.push_back(beginWord);
        dfs(nextNodeList,beginWord,endWord,ret,temp);        
        return ret;
    }

    void dfs(unordered_map<string, unordered_set<string>> &nextNodeList,string beginWord,string endWord,vector<vector<string>> &ret,vector<string> &temp)
    {
        if(beginWord == endWord)
        {
            ret.push_back(temp);
            return;
        }
        for(auto item : nextNodeList[beginWord]) 
        {
            temp.push_back(item);
            dfs(nextNodeList,item,endWord,ret,temp);
            temp.pop_back();
        }
    }
};

//上面代码的更简洁和理解的写法
class Solution {   
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
    	
    	unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.find(endWord) == dict.end()) 
            return {};
        unordered_map<string, unordered_set<string>> nextNodeList;
        unordered_set<string> q[2] = {{beginWord},{endWord}};
        bool success = false;
        dict.erase(beginWord); 
        dict.erase(endWord);
        int cur = 0;
        while(!q[cur].empty() && !q[1-cur].empty())
        {
        	if(q[cur].size() > q[1-cur].size())
        		cur = 1-cur;
            unordered_set<string> nextLevel;
            for (auto item : q[cur])
            {
                for (int l = 0; l < item.size(); ++l) 
                {
                	auto next = item;
                    for (char c = 'a'; c <= 'z'; ++c)
                    {	
                        next[l] = c;
                        if(q[1-cur].find(next) != q[1-cur].end()) 
                        {
                            if(cur == 0) 
                            	nextNodeList[item].insert(next);
                            else 
                            	nextNodeList[next].insert(item);
                            success = true;
                        }
                        else if(dict.find(next) != dict.end())
                        {
                            nextLevel.insert(next);
                            if(cur == 0) 
                            	nextNodeList[item].insert(next);
                            else 
                            	nextNodeList[next].insert(item);
                        }
                    }
                }
            }
            if(success)
            	break;
            for(auto item : nextLevel)
                dict.erase(item); 
            q[cur] = nextLevel;
            cur = 1-cur;
        } 

        if(!success)
        	return {};
        vector<vector<string>> ret;
        vector<string> temp;
        temp.push_back(beginWord);
        dfs(nextNodeList,beginWord,endWord,ret,temp);        
        return ret;
    }

    void dfs(unordered_map<string, unordered_set<string>> &nextNodeList,string beginWord,string endWord,vector<vector<string>> &ret,vector<string> &temp)
    {
        if(beginWord == endWord)
        {
            ret.push_back(temp);
            return;
        }
        for(auto item : nextNodeList[beginWord]) 
        {
            temp.push_back(item);
            dfs(nextNodeList,item,endWord,ret,temp);
            temp.pop_back();
        }
    }
};


