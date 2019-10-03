题目描述:

The count-and-say sequence is the sequence of integers 
beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as"one 1"or 11.
11 is read off as"two 1s"or 21.
21 is read off as"one 2, then one 1"or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

class Solution {
public:
    string countAndSay(int n) {

    	if(n<=1)
    		return "1";
    	string cur = "1";
    	string next = "";
    	int k = 1;
    	while(k<n)
    	{   
            int len = cur.length();
    		int i =0;
    		while(i<len)
    		{
    			char c = cur[i];
    			int cnt = 1;
    			int j = i+1;
    			while(j<len && cur[j]==c)//这里不是一个一个的判断
    			{                    //而是一次操作将满足条件的都判断完
    				cnt++;
    				j++;
    			}
    			next+=to_string(cnt)+c;
    
    			i=j;
    		}
    		cur = next;
    		k++;
    		next = "";
    	}
    	return cur;       
    }

};