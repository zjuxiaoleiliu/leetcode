目描述

A robot is located at the top-left corner of a m x n grid 
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid 
(marked 'Finish' in the diagram below).

How many possible unique paths are there?



Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

//动态规划：递推公式是可能到达当前的途径之和
class Solution {
public:
    int uniquePaths(int m, int n) {

    	if(m < 1 || n < 1)
    		return 0;
    	vector<unsigned> sum(n,0);

    	for(int i = 0;i < m;i++)
    	{
    		for(int j = 0;j < n;j++)
    		{   //分情况讨论,到达当前位置有两种途径:从左边到达和上面到达
    			if(i == 0 && j == 0)
    				sum[j] = 1;
    			else
    			{ 

    			unsigned left = 0;//根据递推公式合理的初始化
    			if(j !=0)
    				left = sum[j-1];
    			unsigned up = 0;
    			if(i != 0)
    				up = sum[j];
    			sum[j] = left + up;
    		    }

    		}
    	}

    	return sum[n-1];

    }
};