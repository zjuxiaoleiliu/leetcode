题目描述:

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as1and0respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {

        int m = obstacleGrid.size();
        if(m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        vector<unsigned> sum(n,0);

        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {   //这个条件可以行使一票否决权
                if(obstacleGrid[i][j] == 1)//流式处理，先不忙操作，先对当前情况进行判断
                    sum[j] = 0;            //再根据判断结果进行对应的操作
                else//下边就是能够到达的情况
                {   
                    if(i == 0 && j == 0)
                        sum[j] = 1 ;
                    else
                    { 
                        unsigned left = 0;//根据递推公式合理的进行初始化
                        if(j !=0)
                            left = sum[j-1];
                        unsigned up = 0;
                        if(i != 0)
                            up = sum[j];
                        sum[j] = left + up;
                    }

                }

            }
        }
        return sum[n-1];       
    }
};