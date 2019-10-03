题目描述:

Implement regular expression matching with support for'.'and'*'.

'.' Matches any single character.//这里的正则表达式'.'应该匹配任何非空的单个字符
'*' Matches zero or more of the preceding element.
                                 //完全匹配
The matching should cover the entire input string (not partial).
       //函数原型
The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

//递归解决方案
//两个参数数的递归函数设计：选择一个参数为准进行讨论，作为
//标准的那个参数的讨论应该层层递进，逐步升级，
//这里选择正则表达式参数作为递归函数设计的标准，
//针对当前正则表达式字符的不同情况，可以左右递归函数的调用去向
//正则表达式中情况比较多，又能左右递归函数调用方向，而要匹配的
//字符串中只有一般意义上的字符，情况少，又不能左右递归函数的调用走向
//故这里不适合作为递归函数设计的标准进行讨论

//这个递推是从左向右进行,要考虑正则表达式的解码规则
class Solution {
public:          
    bool isMatch(const char *s, const char *p) {
      
    	if(*s=='\0' && *p=='\0')
    		return true;
    	if(*s!='\0' && *p=='\0')
    		return false;
    	if(*(p+1)=='*')//当前位置怎么匹配，依赖于它之后的字符，如果它之后的字符是一个普通字符
    	{              //则只考虑当前位置自己进行匹配，如果它后面的字符为*，则当前位置的匹配
                       //需要和它后面的*作为一个整体考虑，不能单独解码，这也是正则表达式解码
                       //的规则
    		if(*s!='\0' && (*p=='.' || *p==*s))
    			       //大于1次             1次                0次               
    			return isMatch(s+1,p) || isMatch(s+1,p+2) || isMatch(s,p+2);
                //return isMatch(s+1,p) || isMatch(s,p+2);
                //isMatch(s+1,p)包含isMatch(s+1,p+2)的情况，isMatch(s+1,p+2)成功，isMatch(s+1,p)一定成功
    		else     
    			return isMatch(s,p+2);//这个方向时s可以为空
    	}
        else if(*s!='\0' && (*p=='.' || *p==*s))
    		return isMatch(s+1,p+1);
    	else return false;       
    }
};



//动态规划求解：dp[i][j]代表s{0...i-1}和p{0...j-1}是否完全匹配
class Solution { 
public:  
    bool isMatch(string s, string p) { 

        int slen = s.length();
        int plen = p.length();  
        if(slen==0 && plen==0)
        	return true;  
        if(slen!=0 && plen==0)  
        	return false;  
        vector<vector<bool>> dp(slen+1,vector<bool>(plen+1,false));   
        dp[0][0] = true;   
        for(int i = 2; i<=plen; i++)
        {
        	if(p[i-1]=='*')  
        		dp[0][i] = dp[0][i-2];
        }//根据我们对dp的初始化情况dp[i][0]=false，1<=i<=slen天然的已经计算出正确的值了   
        for(int i = 1; i <= slen; i++)
        {  
            for(int j = 1; j <= plen; j++)
            {  
                if(p[j-1]==s[i-1] || p[j-1] == '.')  
                    dp[i][j] = dp[i-1][j-1];  
                else if(j>1 && p[j-1] == '*')//如果要使用*匹配时*前面必须得有字符
                { 
                	if(p[j-2]!=s[i-1] && p[j-2] != '.')
                		dp[i][j]=dp[i][j-2];//0次
                	else         //多于1次         1次              0次
                		dp[i][j]=dp[i-1][j] || dp[i-1][j-2] || dp[i][j-2];
                        //dp[i][j]=dp[i-1][j] || dp[i][j-2];         
                }      //dp[i-1][j]包括dp[i-1][j-2]的情况，dp[i-1][j-2]成功，dp[i-1][j]一定成功
            }  
        }   
        return dp[slen][plen];  
    } 
}; 

