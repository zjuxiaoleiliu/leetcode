给定一个整数，写一个函数来判断它是否是 3 的幂次方。

示例 1:

输入: 27
输出: true
示例 2:

输入: 0
输出: false
示例 3:

输入: 9
输出: true
示例 4:

输入: 45
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        if( n == 1)
            return true;
        while(n%3 == 0) n /= 3;
        if(n == 1)
            return true;
        else
            return false;        
    }
};

//3的幂次质因子只有3，而整数范围内的3的幂次最大是1162261467
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        if( n == 1)
            return true;
        int theMax = pow(3, int(log(INT_MAX) / log(3)));
        if(theMax%n == 0)
        	return true;
        else
        	return false;        
    }
};