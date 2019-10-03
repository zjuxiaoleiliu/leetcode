题目描述：
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are+,-,*,/. Each operand may be an integer or another expression.
Some examples:
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

逆波兰式（Reverse Polish notation，RPN，或逆波兰记法），也叫后缀表达式（将运算符写在操作数之后）

解决方案：从左到右将表达式的元素放入栈中，遇到运算符时，从栈中取出两个元素进行这个运算，将运算结果放入
栈中，继续对表达式进行扫描
/*
c++ 如何将string 转化int的方法
1,在C标准库里面，使用atoi(表示 ascii to integer)是把字符串转换成整型数的一个函数
int atoi(const char *nptr) 
2, 在C++标准库里面，使用stringstream：(stringstream 可以用于各种数据类型之间的转换)
#include <sstream>
#include <string>
std::string text = "152";
int number;
std::stringstream ss;
ss << text;//可以是其他数据类型
ss >> number; //string -> int
3，int stoi (const string& str, size_t* idx = 0, int base = 10);
Parses str interpreting its content as an integral number of the specified base,
 which is returned as an int value.
If idx is not a null pointer, the function also sets the value of idx to 
the position of the first character in str after the number.

std::to_string

string to_string (int val);
string to_string (long val);
string to_string (long long val);
string to_string (unsigned val);
string to_string (unsigned long val);
string to_string (unsigned long long val);
string to_string (float val);
string to_string (double val);
string to_string (long double val);
Convert numerical value to string
Returns a string with the representation of val.
*/

/*
atoi()和stoi()的区别
相同点：
①都是C++的字符处理函数，把数字字符串转换成int输出
②头文件都是#include<cstring>
不同点：
①atoi()的参数是 const char* ,因此对于一个字符串str我们必须调用 c_str()的方法把这个string转换成 const char*类型的,而stoi()的参数是const string*,不需要转化为 const char*；
②stoi()会做范围检查，默认范围是在int的范围内的，如果超出范围的话则会runtime error！
而atoi()不会做范围检查，如果超出范围的话，超出上界，则输出上界，超出下界，则输出下界；
*/
class Solution {
public:
    int evalRPN(vector<string> &tokens) 
    {   

    	stack<int> temp;
    	for(auto iter = tokens.begin();iter!=tokens.end();iter++)
    	{
    		string str = *iter;
    		if(str == "+" || str == "-" || str == "*" || str == "/")
    		{
               int two = temp.top();
               temp.pop();
               int one = temp.top();//注意这里的操作数顺序不要搞反了
               temp.pop();
               int ret = 0;
               if(str == "+")
               	ret = one + two;
               if(str == "-")
               	ret = one - two;
               if(str == "*")
               	ret = one * two;
               if(str == "/")
               	ret = one / two;
               temp.push(ret);//抽象出来的公共操作
    		}
    		else
    			temp.push(atoi(str.c_str()));//c_str()将std::string转化为标准C风格字符串    		
    	}
    return temp.top();    	
    }
};


