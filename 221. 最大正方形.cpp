在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4



/*
动态规划，时间复杂度为O(n^2)
dp[i][j]表示以点(i, j)为右下角的正方形的最大边长；状态转移方程：
dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j-1]),min(dp[i-1][j - 1], dp[i - 1][j])) + 1;

当我们判断以某个点为正方形右下角时最大的正方形时，那它的上方，
左方和左上方三个点也一定都是某个正方形的右下角，否则该点为右下角的正方形最大就是它自己了。
这是定性的判断
*/  
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        if(matrix.empty() || matrix[0].empty()) 
        	return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int ret = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) 
        {
            for(int j = 0; j < n; ++j) 
            {
                if(i == 0 || j == 0) 
                	dp[i][j] = matrix[i][j] - '0';
                else if(matrix[i][j] == '1') 
                {
                	dp[i][j] = 1;
                	if(dp[i-1][j-1] && dp[i][j-1] && dp[i-1][j])
                		dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j-1]),min(dp[i-1][j - 1], dp[i - 1][j])) + 1;
                }
                ret = max(ret, dp[i][j]);
            }
        }
        return ret * ret;
    }
};

//上面的代码我们还可以优化到只使用维数的数组保存动态规划的中间信息
//逐行更新，每一行按照从右向左的顺序计算