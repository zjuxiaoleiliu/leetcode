题目描述:

Given two numbers represented as strings, 
return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.


//模拟乘法的运算过程,两个非负数相乘，结果的位数至多为这两个非负数位数之和
//不妨设这两个非负数位数分别为x,y，取这两个位数的最大的两个数相乘
//即(10^x-1)(10^y-1)=10^(x+y)-10^x-10^y+1=9*10^(x+y-1)+1*10^(x+y-1)-10^x-10^y+1
//结果为一个x+y位数
class Solution {
public:
	string multiply(string num1, string num2) {
        
        if(num1.length()==0 || num2.length()==0)
        	return "";
        string ret(num1.size()+num2.size(),'0');
        for(int i=num1.size()-1;i>=0;--i) 
        {   
            int carry = 0;
        	//位置对应关系利用平移不变性
           //它最初位于ret中的位置为：num1.size()+num2.size()-1-(num1.size()-1-i)
        	int k  = num1.size()+num2.size()-1-(num1.size()-1-i);//初始化指针指向结果中的位置
            for(int j=num2.size()-1;j>=0;--j) 
            {
                int sum = (num1[i]-'0')*(num2[j]-'0')+(ret[k]-'0')+carry;
                ret[k] = sum%10 + '0';
                carry = sum/10;
                k--;
            }
            if(carry)
            	ret[k] = carry+'0';      
        }
        int i = 0;
        while(i<ret.size() && ret[i]=='0') ++i;
        return i==ret.size()?"0":ret.substr(i);
    }          //例如123456*0=0
};

