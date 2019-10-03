题目描述:

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true



解决方案思路：栈的抵消的思想，没用的抵消掉，去除，
class Solution {
public:
    bool isValid(string s) {

    	stack<char> stk;

    	for(int i = 0;i < s.length();i++)
    	{
    		char elem = s[i];
    		if(elem!='(' && elem!=')' && elem!='[' && elem!=']' && elem!='{' && elem!='}')
    			return false;
    		else
    		{   

    			if(stk.empty())
    				stk.push(elem);
    			else
    				{
    					char temp = stk.top();
    			        if((temp=='(' && elem==')') || (temp=='[' && elem==']') || (temp=='{' && elem=='}'))
    			        	stk.pop();
    			        else
    			        	stk.push(elem);
    			    }
    		}

    	}
    
    if(stk.empty())
    	return true;
    else
    	return false;  
    }
};

