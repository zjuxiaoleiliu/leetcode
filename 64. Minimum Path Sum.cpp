题目描述:

Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes 
the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.


class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {

    	int m = grid.size();
    	if(m == 0)
    		return 0;
    	int n = grid[0].size();
    	if(n == 0)
    		return 0;

    	vector<int> minSum(n,0);

    	for(int i=0;i<m;i++)
    	{
    		for(int j=0;j<n;j++)
    		{   //分情况讨论：根据能不能从左边到达，从上边到达
                //先讨论两种途径都不能达到的情况
    			if(i == 0 && j == 0)
    				minSum[j] = grid[i][j];
    			else 
    			{   //下边的就是当前至少有一种途径能够达到的情况
    				int up = INT_MAX;//初始化为一个不可能的值，根据递归公式做出合理
    				if(i > 0)        //的初始化
    					up = minSum[j];
    			    int left = INT_MAX;
    			    if(j > 0)
    			    	left = minSum[j-1];

    			    minSum[j] = min(left,up)+grid[i][j];   			    
    			}
                
    		}
    	}
    	return minSum[n-1];       
    }
};