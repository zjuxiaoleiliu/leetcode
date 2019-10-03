题目描述:

Validate(合法的) if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true


"."	        false
"+e10"	    false
"e12"	    false
"+1."	    true
"+.1"	    true
"1e10"	    true
"0e10"	    true
".e10"	    false
"1.1e+10"   true
"1.2e-10"   true
"--1"	    false
"11ee1"	    false
"1.-1e-1"   false
"abc"	    false
" 1.1"	    true
"- 1.2"	    false
" "         false
Note: It is intended for the problem statement to be 
ambiguous. You should gather all requirements up 
front before implementing one.
/*
表示数值的字符串遵循模式：
[+|-]A[.[B]][e|E [+|-]C] 或者 [+|-].B[e|E [+|-]C]
其中A,B,C为无符号整数
根据这个匹配模式,按照从左到右的顺序逐元素，逐部分的判断
因为我们对于各个部分的判断使用的是一个个的
if语句,或者一个个的while语句，所以不是这一部分的就不会进入
这些语句执行
*/
class Solution {
public:
	bool isNumber(string s){
        
        int n = s.length();
        if(n == 0) 
        	return false;        
        int i = 0; 
        //字符串前面的空格
        while(i < n && s[i] == ' ') ++i;
        if(i == n)
        return false;        
        //正负号
        if(i < n && (s[i] == '+' || s[i] == '-')) ++i;  
        // A.B从左往右依次判断存在性
        //整数部分
        bool int_num = false;
        while(i < n && isdigit(s[i]))//判断有没有整数部分
        {                       //没有的话，这个操作不会发生
        	if(int_num == false)
        		int_num = true;
            ++i;
        }
        //小数点
        bool dot = false;
        if(i < n && s[i] == '.')
        {
        	dot = true;
            ++i; 
        }
        //小数部分
        bool tail = false;
        while(i < n && isdigit(s[i]))
        {
        	if(tail == false)
        		tail = true;
            ++i;
        }
           //短路判断原则
        //到达这个阶段，如果int_num存在的话，一定合法
        //如果int_num不存在的话，必须要有小数点和小数部分
        if(!(int_num || (dot && tail)))
        	return false;
        //指数部分
        if(i < n && (s[i]=='e' || s[i]=='E'))//不满足每一部分的条件，就不会 
        {                  //进入这一部分执行这一部分的判断操作
            ++i;
            if(i < n && (s[i] == '-' || s[i] == '+'))
            	++i;
            bool ee = false;
            while(i < n && isdigit(s[i]))
            {
            	if(ee == false)
            		ee = true;
                ++i;
            }
            if(!ee) 
            	return false;
        }
        //字符串尾部的空格
        while(i < n && s[i] == ' ') ++i;       
        return i == n ;
    }
};


//C风格函数接口
class Solution {
public:
	bool isNumber(const char *s){
        
        if(s==nullptr)
        	return false;
        int n = strlen(s);
        if(n == 0) 
        	return false        
        int i = 0; 
        //字符串前面的空格
        while(i < n && s[i] == ' ') ++i;        
        //正负号
        if(i < n && (s[i] == '+' || s[i] == '-')) ++i;  
        //整数部分
        bool int_num = false;
        while(i < n && isdigit(s[i]))
        {
        	if(int_num == false)
        		int_num = true;
            ++i;
        }
        //小数点
        bool dot = false;
        if(i < n && s[i] == '.')
        {
        	dot = true;
            ++i; 
        }
        //小数部分
        bool tail = false;
        while(i < n && isdigit(s[i]))
        {
        	if(tail == false)
        		tail = true;
            ++i;
        }   //短路判断原则
        if(!(int_num || (dot && tail)))
        	return false;
        //指数部分
        if(i < n && (s[i]=='e' || s[i]=='E'))//不满足每一部分的条件，就不会 
        {                  //进入这一部分执行这一部分的判断操作
            bool ee = false;
            ++i;
            if(i < n && (s[i] == '-' || s[i] == '+'))
            	++i;
            while(i < n && isdigit(s[i]))
            {
            	if(ee == false)
            		ee = true;
                ++i;
            }
            if(!ee) 
            	return false;
        }
        //字符串尾部的空格
        while(i < n && s[i] == ' ') ++i;
        
        return i == n ;
    }
};



