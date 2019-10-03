给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。

示例:

输入: 13
输出: 6 
解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。

提示1：
Beware of overflow.


//暴力法,超时
class Solution {
public:
    int countDigitOne(int n) {

    	if(n < 1)
    		return 0;
    	int ret = 0;
    	for(int i = 1;i <= n;i++)
    	{
    		int number = i;
    		while(number)
    		{
    			if(number%10 == 1)
    				ret++;
    			number/=10;
    		}
    	}
    	return ret;        
    }

}; 

//通过观察，找到规律，直接计算出来的递归解法
class Solution {
public:
    int countDigitOne(int n)
    {
        if(n < 1)
    		return 0;	
    	int len = 0;
    	int number = n;
    	while(number)
    	{
    		len++;
    		number/=10;  
        }
    	if(len == 1)
    		return 1;
    	int ret = 0;
    	int temp = pow(10,len-1);
    	int first = n/temp;
    	if(first == 1)
    	{
    		ret+= (n%temp)+1;//最高位为1出现的次数
            ret+=1*(len-1)*(temp/10);

    	}
    	else
    	{
    		ret+= temp;//最高位为1出现的次数
    		ret+=first*(len-1)*(temp/10);//比最高位小的数出现1的次数
    	}
    	ret+= countDigitOne(n%temp);
    	return ret;
    }

}; 