题目描述:

Given an array of non-negative integers, 
you are initially positioned at the first index of the array.

Each element in the array represents your maximum 
jump length at that position.

Determine if you are able to reach the last index.

For example:
A =[2,3,1,1,4], return true.

A =[3,2,1,0,4], return false.

//解法1：贪心算法
/*
当我遍历数组A时，定义一个maxJump用来存储截止到当前位置之前
所能跳跃的最大的步数，例如，截止到A[2]之前，
我们所能跳跃到的最远的距离为位置4 ；
当maxJump < i 时，说明截止到位置i之前，
我们所能到达的最远位置maxJump小于当前位置i，即我们不能再进一步了，
也就是说我们无法到达位置i ，返回false；
反之，说明我们能够到达位置i,那么就将maxJump 
更新为截止到i时我们所能到达的最远的位置；
若遍历结束仍然没有触发 false ，
说明我们成功的到达了数组A的最后一个位置，返回 true 。
*/
//从前向后的贪心策略
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        if(n<1)
            return false;
        if(n == 1)
            return true;
        int maxJump = nums[0];
        for(int i = 1; i < n; i++) 
        {   //能不能跳到当前位置
            if(maxJump < i)//在i之前已经无法再前进了
                return false;
            else
                {
                    maxJump = max(maxJump, nums[i]+i);
                    if(maxJump>=n-1)
                        return true;
                }
        }
        return true;        
    }
};
//方法2：动态规划
/*
dp[i]的含义为从位置i开始能不能到达最后的位置
则递推公式为：
dp[i-1] =  || dp[j],(i-1)+1 <= j <= A[i-1]+(i-1)
//这个时间复杂度为o(n^2),C++实现LeetCode 836ms,java实现222ms
用vector实现的dp数组 C++代码会运行超时
*/
class Solution {
public:
    bool canJump(int A[], int n) {
        if(n<1)
        	return false;
        if(n == 1)
        	return true;
    	bool dp[n] = {false};
    	dp[n-1] = true;
        for(int i = n-2; i>=0; i--) 
        {  //这里对j进行遍历时，我们贪心的认为跳的步长越长，越容易到达末尾
            for(int j = A[i];j >= 1;j--)
            {   
            	if(i+j>=n-1)
            	{
            		dp[i] = true;
            		break;
            	}
            	else if(i+j<n-1 && dp[i+j])
            	{
            		dp[i] =true;
            		break;
            	}            	
            }
        }
        return dp[0];        
    }
};
//方法3：
//有点类似于广度优先的思想，每一次
//更新能到到达的所有的位置的状态标记，看一看最后能不能
//到达最后的位置，即最后位置的状态标记
//时间复杂度为o(n^2),这LeetCode上会超时
class Solution {
public:
    bool canJump(int A[], int n) {

    	if(n<1)
        	return false;
        if(n == 1)
        	return true;
        //广度优先遍历，将能够到的位置设置为true，最后
        //看能不能到达位置n-1,即位置n-1处的状态标记
        bool flag[n] = {false};
        flag[0]=true;
        for(int i=0;i < n;++i)
        {   
        	if(flag[i] == true)
            {
            	for(int j = 1; j <= A[i]; j++)
            	{
                    // 这里要判断是否越界,超过n说明可以到达
                    if(i + j < n)
                    	flag[i + j] = true;
                    else
                        return true;
                }                    
            }
        }
        return flag[n-1];
    }
};
//从前向后的动态规划
//dp[i]的含义为从开始起点能不能达到位置i
//C++实现16ms,遍历j时不使用从后向前的贪心策略，C++
//实现运行时间为1308ms
class Solution {
public:
    bool canJump(int A[], int n) {

    	if(n<1)
        	return false;
        if(n == 1)
        	return true;
        bool dp[n] = {false};
        dp[0]=true;
        for(int i=1;i < n;++i)
        {   
            for(int j = i-1; j>=0; j--)
            {
                if(dp[j] && j+A[j]>=i)
                {
                	dp[i] = true;
                	break;
                }                   
            }
            //if(dp[i]==false)这一步是剪枝加快速度
            	//return false;
        }
        return dp[n-1];
    }
};

