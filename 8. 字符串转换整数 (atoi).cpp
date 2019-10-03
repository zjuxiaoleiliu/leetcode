题目描述:
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below 
and ask yourself 
what are the possible input cases.

Notes: It is intended for this problem 
to be specified vaguely(含糊地，不详细地) 
(ie, no given input specs(说明,规范)). You are responsible 
to gather all the input requirements up front.

spoilers(剧透) alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace 
characters(空白字符是指在屏幕上不会显示出来的字符
(如空格，制表符tab，回车换行等)) as necessary 
until the first non-whitespace 
character is found. Then, starting from this character, 
takes an optional initial plus or minus sign followed 
by as many numerical digits as possible, 
and interprets them as a numerical value.

The string can contain additional characters after 
those that form the integral number(整数), 
which are ignored and have no effect 
on the behavior of this function.

If the first sequence of non-whitespace characters in str 
is not a valid integral number, 
or if no such sequence exists because either str is empty 
or it contains only whitespace characters, 
no conversion is performed.

If no valid conversion could be performed, a zero value 
is returned. If the correct value is out of the range 
of representable values, INT_MAX (2147483647) 
or INT_MIN (-2147483648) is returned.

/*
转换前要跳过左边的空白字符，得到的第一个非空白字符要先判断是否是到达
了字符串的末尾，如果到达了末尾，可以直接下结论返回;如果没有到达字符串的
末尾，那它就是一个合法的非空白字符，要先判断是否是符号位，进行过符号位的
判断操作之后，就是计算整数值(针对数字字符而言)直到越过数字字符的右边界
计算过程停止，返回计算结果
*/
class Solution {
public:
    int myAtoi(const char *str) {

        if(str==nullptr) 
        	return 0;
        const char *p = str;
        while(isspace(*p)) p++;
        if(*p == '\0')
        	return 0;
        int sign = 1;
        if(*p == '-')//如果没有符号字符不会进入这个条件判断操作，这个
        {            //操作不会发生
        	sign = -1;
        	p++;
        }
        else if(*p == '+')
        	p++;
        long ret = 0;
        while(*p!='\0')
        {
        	if(0<= *p-'0' && *p-'0'<=9)
        	{
        		ret = 10*ret+sign*(*p-'0');
        		if(ret >= INT_MAX)
        			return INT_MAX;
        		else if(ret <= INT_MIN)
        			return INT_MIN;
        	}
        	else
        		return (int)ret;//已经越过了合法数字字符的右边界
        	p++;
        }
        return (int)ret;     
    }
};