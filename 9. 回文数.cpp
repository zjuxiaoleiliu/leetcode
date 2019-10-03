断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:

你能不将整数转为字符串来解决这个问题吗？


/*
设n是一任意自然数。若将n的各位数字反向排列所得自然数n1与n相等，
则称n为一回文数。例如，若n=1234321，则称n为一回文数；
但若n=1234567，则n不是回文数。
*/

//直接方法
class Solution {
public:
    bool isPalindrome(int x) {

    	if(x < 0)
    		return false;

    	int n = 0;//位数
    	int num = x;

    	while(num!=0)
    	{
    		n++;
    		num = num/10;
    	}

    	for(int i = 0;i<n/2;i++)
    	{

    		int l = (x/(int)pow(10,n-1-i))%10;
    		int r = (x/(int)pow(10,i))%10;
    		if(l!=r)
    			return false;

    	}

    	return true;
        
    }

};

//还是直接方法，但是将数转化为了字符串，不符合题目要求，使用额外空间了
class Solution {
public:
    bool isPalindrome(int x) {

    	if(x < 0)
    		return false;

    	string s = to_string(x);
    	int n = s.length();//转换为字符串后可以便利我们的
    	for(int i = 0;i<n/2;i++)//针对解决问题要做的操作
    	{                     //例如，得到长度，得到每一位的值
    		if(s[i]!=s[n-1-i])
    			return false;
    	}

    	return true;
        
    }

};


//比较好的解法：直接求出翻转后的整数值和x比较
//如果x是回文数的话，翻转后的整数可能不会溢出，如果原数不溢出
//翻转后的数发生了溢出现象，说明原数x一定不是回文数
class Solution {
public:
    bool isPalindrome(int x) {

    	if(x < 0)
    		return false;

    	int temp = x;
    	unsigned reverse = 0;
    	while(temp!=0)//求翻转数字的成熟代码操作
    	{
    		reverse = 10*reverse+temp%10;
    		temp/=10;
    	}

        //上面的解法是一位一位的比较，这样的比较需要手工操作进行
        return reverse == x;//而这里直接将翻转后的数字求出来，使用相等运算符直接得出结论
              
    }

};











