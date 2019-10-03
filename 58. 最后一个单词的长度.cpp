题目描述:
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指由字母组成，但不包含任何空格的字符串。

示例:

输入: "Hello World"
输出: 5

class Solution {
public:
    int lengthOfLastWord(const char *s) {

    	if(s == nullptr)
    		return 0;
    	int n = strlen(s);
    	if(n == 0)
    		return 0;
    	int cnt = 0;
    	bool isWord = false;
    	for(int i = n-1;i>=0;i--)
    	{   
    		if(s[i] == ' ')//流式处理，对当前元素先进行判断，再根据判断结果决定要进行的操作
    		{
    			if(isWord == true)
    				return cnt;

    		}
    		else
    		{  
    			if(isWord == false)
    				isWord = true;
    			cnt++;
    		}

    	}

    	return cnt;

        
    }
};


class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.length();
        if(n == 0)
            return 0;
        int cnt = 0;
        bool isWord = false;
        for(int i = n-1;i>=0;i--)
        {   
            if(s[i] == ' ')//流式处理，对当前元素先进行判断，再根据判断结果决定要进行的操作
            {
                if(isWord == true)
                    return cnt;

            }
            else
            {  
                if(isWord == false)
                    isWord = true;
                cnt++;
            }

        }

        return cnt;

        
    }
};