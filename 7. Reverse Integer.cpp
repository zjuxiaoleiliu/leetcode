题目描述
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers(剧透).

Have you thought about this?
Here are some good questions to ask before coding.
Bonus points for you if you have already thought through this!

If the integer s last digit is 0, what should the output be? ie, 
cases such as 10, 100.

Did you notice that the reversed integer might overflow? 
Assume the input is a 32-bit integer, then the reverse of 1000000003 
overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception 
is not an option? You would then have to re-design the function 
(ie, add an extra parameter).

class Solution {
public:
    int reverse(int x) {

        long num = 0;//取绝对值可能会发生溢出
        if(x<0)
            num = -(long)x;
        else num = x;
        long reverse = 0;
        while(num!=0)//直接将翻转后的数字计算出来
        {
            reverse = 10*reverse+num%10;
            num/=10;
        }
        if(x<0)
            reverse = -reverse;
        if(reverse<INT_MIN || reverse>INT_MAX)
            return 0;
        else
            return (int)reverse;
        
    }
};

