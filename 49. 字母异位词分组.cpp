题目描述:

Given an array of strings, return all groups 
of strings that are anagrams.
//一种把某个词或句子的字母的位置（顺序)加以改换所形成的新词，
//英文叫做anagram，词典把这个词翻译成“变位词”。
Note: All inputs will be in lower-case.

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {

    	vector<string> ret;
    	int n = strs.size();
    	if(n == 0)
    		return ret;
    	unordered_map<string,int> m;
    	for(int i = 0;i<n;i++)//流式处理
    	{
    		string temp = strs[i];
    		sort(temp.begin(),temp.end());
    		if(m.find(temp) == m.end())
            //第一次出现时保存的是位置，方便后面触发它是异位词时加入它时知道它的位置    
    			m[temp] = i;
    		else
    		{
    		//由于第一次加入映射中的词，需要由后面再次出现的词
    	    //来决定它是不是异位词，当再次出现时才能触发第一个出现的
    		//词的添加操作
    			if(m[temp]!=-1)
    			{
    				ret.push_back(strs[m[temp]]);
    				//触发状态改变
    				m[temp]=-1;//置为-1表明映射中的词已经明确是异位词了
    			}//映射中保存的值既可以为下标位置，也可以为一个说明状态的标志值flag
    			ret.push_back(strs[i]);
    			
    		}
    	}

    	return ret;
            
    }
};


//和上面一样的思路，不过这里需要进行两次遍历
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {

        vector<string> ret;
        int n = strs.size();
        if(n == 0)
            return ret;
        unordered_map<string,int> m;//这里映射中保存的值只有一个含义：计数值
        for(int i = 0;i<n;i++)
        {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            if(m.find(temp) == m.end())   
                m[temp] = 1;
            else
                m[temp]++;
        }
        for(int i = 0;i < n;i++)//流式处理
        {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            if(m.find(temp) != m.end() && m[temp] > 1) 
                ret.push_back(strs[i]);   
        }
        return ret;           
    }
};
//同样的思路，不同的实现
class Solution {
public:
    vector<string> anagrams(vector<string> &strs)
    {

        vector<string> ret;
    	int n = strs.size();
    	if(n == 0)
    		return ret;
        unordered_map<string,vector<string>> m;
        for(int i = 0;i < n;i++)
        {
        	string temp =strs[i];
            sort(temp.begin(),temp.end());
            if(m.find(temp)!=m.end())
                m[temp] = {strs[i]};
            else
                m[temp].push_back(strs[i]);
        }
        for(auto iter=m.begin();iter!=m.end();iter++)
        {
        	if(iter->second.size()>1)
        		ret.insert(ret.end(),iter->second.begin(),iter->second.end());
       }
       return ret;
    }
};
//上面思路的不用排序实现
class Solution {
public:
    vector<string> anagrams(vector<string> &strs)
    {

        vector<string> ret;
    	int n = strs.size();
    	if(n == 0)
    		return ret;
        unordered_map<string,vector<string>> m;
        for(int i = 0;i<n;i++)
        {
            vector<int> cnt(26, 0);            
            for(auto c:strs[i]) 
            	++cnt[c-'a'];
            string temp = "";
            for(auto count:cnt)
            	temp += to_string(count);
            if(m.find(temp)!=m.end())
                m[temp] = {strs[i]};
            else
                m[temp].push_back(strs[i]);
        }
        for(auto iter=m.begin();iter!=m.end();iter++)
        {
        	if(iter->second.size()>1)
        		ret.insert(ret.end(),iter->second.begin(),iter->second.end());
       }
       return ret;
    }
};

