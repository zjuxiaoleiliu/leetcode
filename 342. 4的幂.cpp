给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。

示例 1:

输入: 16
输出: true
示例 2:

输入: 5
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？

class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n <= 0)
            return false;
        if( n == 1)
            return true;
        while(n%4 == 0) n /= 4;
        if(n == 1)
            return true;
        else
            return false;
        
    }
};


class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n <= 0 || (n & (n-1))!=0)
            return false;
        //所以4的倍数1那位一定是奇数位 0x5=0101
        return (n & 0x55555555) !=0;       
    }
};