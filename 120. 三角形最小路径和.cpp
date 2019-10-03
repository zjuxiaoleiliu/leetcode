题目描述:

Given a triangle, find the minimum path sum from top to bottom.
 Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11(i.e., 2 + 3 + 5 + 1 = 11).

Note: 
Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle.

//方法1是我的方法，dps[i]的含义为从三角形的最顶端到当前层的第i个顶点(0为下标起始点)的最短距离
//这里是从上向下进行的动态规划结果更新，因为最底层有size个顶点，所以最后还需要额外的做一个
//在这size个顶点中找出最小的操作

//这个问题其实是一个size步的决策过程，动态规划如何选定一步分解成更小的问题，这个方法选择的是
//确定第一步分解问题，然后从上向下进行更新
//考虑到最顶端只有一个顶点，而最末端有size个顶点，所以我们可以选择确定最后一步分解问题，然后
//从下向上进行更新，这样最后可以直接得出结果，不用做额外的找出最小值的操作



//方法1：我的方法，自上向下更新
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {

    	int size = triangle.size();
    	vector<int> dp(size,INT_MAX);
    	if(size == 1)
    		return triangle[0][0];
    	dp[0] = triangle[0][0];
    	for(int row = 2;row <= size;row++)
    	{
    		int pre = INT_MAX;
    		for(int i = 0;i<row;i++)
    		{   
    			int temp = INT_MAX;
    			if(i == 0)
    			{   
                    temp =dp[i]; 
    				dp[i]=dp[i]+triangle[row-1][i];
    				pre = temp;
    			}
    			else if(i == row-1)
                    dp[i]=pre+triangle[row-1][i];
    				else
    				{   
    					temp =dp[i];
    					dp[i]=min(dp[i],pre)+triangle[row-1][i];
    					pre = temp;
    				}
    		}
            
    	}

    	int min = INT_MAX;
    	for(auto elem:dp)
    	{
    		if(elem < min)
    			min = elem;
    	}

    	return min;

        
    }
};


//方法2:自底向上的方法，这个方法好，最后可以直接得出结果
//这里的辅助数组dp中的元素dp[i]的含义为当前层的第i个节点到
//最后一层的最小路径和
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {

    	int size = triangle.size();
    	if(size == 1)
    		return triangle[0][0];
    	vector<int> dp = triangle[size-1];
 
    	for(int row = size-1;row >=1;row--)
    	{
    		for(int i = 0;i<row;i++)
    		{   

                dp[i]=min(dp[i],dp[i+1])+triangle[row-1][i];
   	
    		}            
    	}
    	return dp[0];      
    }
};

