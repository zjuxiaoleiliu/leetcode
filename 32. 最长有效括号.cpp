题目描述:

给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"


//用栈解决这个问题：匹配  抵消
/*
这题关键的一点是栈中保存index下标位置，而不是保存字符。将index保存在栈中，
然后匹配的index会出栈，全部的抵消掉
剩下的就是不能匹配的index。两个不能匹配的下标index中间的都是能够匹配的，
其中有两个细节需要注意，就是两边的边界：左边界是-1，右边界是s.size()
两个下标i,j之间的元素个数为：i+k+1=j,k=j-i-1.
*/
class Solution {
public:
    int longestValidParentheses(string s) {

    	int n = s.size();
        if(n == 0) 
        	return 0;
        stack<int> stk;
        for(int i = 0;i < n;i++)//遍历一个个元素，流式处理
        {  

        	if(s[i]==')' && !stk.empty() && s[stk.top()] == '(')
                stk.pop();
            else
                stk.push(i);
        }
        if(stk.empty()) 
        	return n;
        int ret = 0;
        int right = n;
        while(!stk.empty())
        {
        	int left = stk.top();
            stk.pop();
            ret = max(ret,right-left-1);
            right = left;
        }
        ret = max(ret,right);
        return ret;
    }
};

//和上面的用栈的思路一样，但是实现不同,我们边做边更新，只需要一次遍历，
//每发生抵消行为(此时发现了一个合法的子串),计算以这个合法子串为结尾的合法子串的长度
//因为可能发生)(())()这样的情况，我们要求的是最长的合法子串，
//此时需要将当前要抵消的合法子串向左尽量的合法扩展，所以这个以当前要抵消的合法子串为
//结尾的合法子串的长度为i减去向左合法扩展遇到的第一个还没有匹配的元素下标
//(从这个第一个还没匹配的元素下标+1开始，到当前下标位置i,之间的元素都是合法匹配的)
//如果栈为空，说明当前发生抵消行为的子串左边都是匹配的，都抵消掉了，所以
//0~i之间的都是合法匹配的，它的长度为i+1
//update更新ret
class Solution {
public:
    int longestValidParentheses(string s) {

        int n = s.size();
        if (n == 0) return 0;       
        int ret = 0;
        stack<int> stk;
        for(int i = 0; i < n; ++i) 
        {
            if(s[i]==')' && !stk.empty() && s[stk.top()]=='(')
            {
            	stk.pop();//向左尽量扩展
                if(!stk.empty())
                	ret = max(ret, i-stk.top());//计算以当前要抵消的合法子串为结尾的
                else                            //最长的合法子串
                	ret = max(ret, i + 1);//说明当前要抵消的合法子串左边已经全部被
            }                           //抵消了，都是合法的
            else
            	stk.push(i);
        }        
        return ret;
    }
};

//动态规划方法,关键是递推公式的获取
//与左括号'('匹配的右括号')'只能在它的后面，与右括号)匹配的左括号只能在
//它的前面，在一个括号序列中每个元素能不能匹配都是确定性的，如果能匹配的话，与哪个位置元素匹配都是确定性的，
//每一个元素只能与给定的元素匹配抵消，没有其它的歧义可能匹配
class Solution {
public:
	int longestValidParentheses(string s) {

		int n = s.size();
        if(n==0 || n==1)
        	return 0;
        vector<int> dp(n, 0);//dp[i]表示以当前位置为终点的最长长度，则只能在')'处更新
        int ret = 0;
        for(int i = 1; i < n; i++) 
        {
            if(s[i] == '(')
            	dp[i] = 0;
            else
            {    
                //更新的核心思想：按照括号的抵消规则，找到和当前位置的右括号匹配的左括号的位置index
               //即这个位置为当前位置匹配的括号中包含的匹配项的左边一位，如果把当前位置匹配后，左边
                //还能继续匹配扩展，则需要把当前位置对应的匹配长度加上左边还能继续扩展的长度
               // 左边能扩展的匹配长度dp[index-1]
               //                           (O)(             O            )
               //                          能把当前位置       |            \
               //                      i匹配掉的位置index                    当前位置i
               //                                     当前位置匹配的括号中间
               //                                        包含的匹配项
                int index = i-dp[i-1]-1;
                if(index>=0 && s[index]=='(')
                {
                    dp[i] = dp[i-1] + 2;
                    if(index-1 >= 0) 
                    	dp[i] += dp[index-1];
                }
            }
            ret = max(ret, dp[i]);
        }

        return ret;
    } 
};


                 