题目描述:

给定两个整数，被除数 dividend 和除数 divisor。
将两数相除，要求不使用乘法、除法和 mod 运算符。
返回被除数 dividend 除以除数 divisor 得到的商。

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
说明:

被除数和除数均为32位有符号整数。
除数不为 0。
假设我们的环境只能存储32位有符号整数，
其数值范围是 [−2^31,  2^31 − 1]。本题中，
如果除法结果溢出，则返回 2^31 − 1。

/*
缺点：时间复杂度为O(n),这里n为问题要求的结果：商n,
当被除数很大、除数很小时，效率非常低(比如，dividend = INT_MAX,divisor=1)
这个算法会超时，所以我们要试着在这个算法的基础上，分析此算法
的瓶颈所在，进行优化，把复杂度降下来，一般o(n)的复杂度我们
要首先看一看能不能往O(logn)方向进行优化
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        //无穷小或者无穷大
        if(divisor==0 || (dividend==INT_MIN && divisor==-1))
            return INT_MAX;
        int sign = ((dividend<0) ^ (divisor<0)) ? -1 : 1;
        //C库函数 long int labs(long int x)返回x的绝对值
        long a = labs(dividend);
        long b = labs(divisor);
        int ret = 0;
        while(a >= b) 
        {
        	a = a-b;
        	ret = ret+sign;//商等于循环能进行的减法操作的次数
        }
        return ret; 
    }
};

 
 
 /* 
 解题思路：被除数=除数×商+余数。
 a = q*b+r(这里a,b均为正数)
 由于本题商为一个32位的正数，任何一个正数可以用一个二进制表示：
 num = a_0*2^0+a_1*2^1+a_2*2^2+...+a_n*2^n(这里a_i等于0或者1)
 我们可以从高到低枚举试探商的各个位是否等于1(商的第i位等于1需要满足
 的条件为：a>=2^i*b)，然后更新a,再试探商的下一位
 假设商q = q_0*2^0+q_1*2^1+q_2*2^2+...+q_i*2^i(这里q_i等于1或者0)
 则：
 a = (q_0*2^0+q_1*2^1+q_2*2^2+...+q_i*2^i)*b+r
 a-q_i*2^i*b = (q_0*2^0+q_1*2^1+q_2*2^2+...+q_(i-1)*2^(i-1))*b+r
 注意：我们必须从高位到低位逐位试探
 */
class Solution {
public:
    int divide(int dividend, int divisor) {

    	if(divisor==0 || (dividend==INT_MIN && divisor==-1))
            return INT_MAX;
        int sign = ((dividend<0) ^ (divisor<0)) ? -1 : 1;
        //C库函数 long int labs(long int x)返回x的绝对值
        long a = labs(dividend);
        long b = labs(divisor);
        long ret = 0;
        for(int i=31; i>=0;i--) 
        {   //即a >= (2^i)*b
            if(a >= b<<i) 
            {
                ret = ret | (1<<i);
                a-=b<<i;
            }
        }
        return sign==1?ret:-ret;        
    }
};


/*
最直观的方法是,用被除数逐个的减去除数,直到被除数小于0。这样做会超时。
那么如果每次不仅仅减去1个除数，计算速度就会增加，但是题目不能使用乘法，
因此不能减去k*除数，我们可以对除数进行左移位操作，
这样每次相当于减去2^k个除数，如何确定k呢，
只要使(2^k)*除数 <= 当前被除数 <(2^(k+1))*除数.
*/
class Solution {
public:
    int divide(int dividend, int divisor) {

        if(divisor==0 || (dividend==INT_MIN && divisor==-1))
            return INT_MAX;
        int sign = ((dividend<0) ^ (divisor<0)) ? -1 : 1;
        long a = labs(dividend);
        long b = labs(divisor);
        long ret = 0;
        while(a >= b) 
        {
        	long temp = b;
            long multiple = 1;//变量的值和状态保持一致
            while(a >= (temp << 1))//从最低位开始试探着寻找k 
            {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            ret += multiple;
        }
        return sign==1?ret:-ret; 
    }
};