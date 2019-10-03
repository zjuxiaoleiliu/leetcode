给定一个整数矩阵，找出最长递增路径的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 
你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

示例 1:

输入: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
输出: 4 
解释: 最长递增路径为 [1, 2, 6, 9]。
示例 2:

输入: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
输出: 4 
解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。


//暴力深度优先遍历dfs
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

    	int m = matrix.size();
    	if(m == 0)
    		return 0;
    	int n = matrix[0].size();
    	if(n == 0)
    		return 0;
    	int ret = 0;
    	for(int i = 0;i < m;i++)
    	{
    		for(int j = 0;j < n;j++)
    		{
    			dfs(matrix,i,j,0,ret);
    		}
    	}
    	return ret;       
    }

    void dfs(vector<vector<int>> &matrix,int i,int j,int cur,int &ret)
    {
		cur++;
		bool flag1 = false;
		if(j-1>=0 && matrix[i][j-1]>matrix[i][j])//左
		{
			flag1 = true;
			dfs(matrix,i,j-1,cur,ret);

		}
		bool flag2 = false;
		if(j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j])//右
		{
			flag2 = true;
			dfs(matrix,i,j+1,cur,ret);
		}
		bool flag3 = false;
		if(i-1>=0 && matrix[i-1][j]>matrix[i][j])//上
		{   
			flag3 = true;
			dfs(matrix,i-1,j,cur,ret);
		}
		bool flag4 = false;
		if(i+1<matrix.size() && matrix[i+1][j]>matrix[i][j])//下
		{
			flag4 = true;
			dfs(matrix,i+1,j,cur,ret);
		}
		if(!flag1 && !flag2 && !flag3 && !flag4)
		{
			if(cur>ret)
			ret = cur;
	    }
		  	
    }
};





//上面的方法会运行超时，使用一个数据结构保存信息，防止不必要的函数调用
//DFS+动态规划
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

    	int m = matrix.size();
    	if(m == 0)
    		return 0;
    	int n = matrix[0].size();
    	if(n == 0)
    		return 0;
    	vector<vector<int>> path(m,vector<int>(n,0));
    	int ret = 0;
    	for(int i = 0;i < m;i++)
    	{
    		for(int j = 0;j < n;j++)
    		{
    			dfs(matrix,path,i,j,0,ret);
    		}
    	}
    	return ret;       
    }

    int dfs(vector<vector<int>> &matrix,vector<vector<int>> &path,int i,int j,int pre,int &ret)
    {
		int p = 1;
		int p1 = 0;
		if(j-1>=0 && matrix[i][j-1]>matrix[i][j])//左
		{
			if(!path[i][j-1])
				p1 = dfs(matrix,path,i,j-1,pre+1,ret);
			else
				p1 = path[i][j-1];
			p = max(p,p1+1);

		}
		int p2 = 0;
		if(j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j])//右
		{
			if(!path[i][j+1])
				p2 = dfs(matrix,path,i,j+1,pre+1,ret);
			else 
				p2 = path[i][j+1];
			p = max(p,p2+1);

		}
		int p3 = 0;
		if(i-1>=0 && matrix[i-1][j]>matrix[i][j])//上
		{   
			if(!path[i-1][j])
				p3 = dfs(matrix,path,i-1,j,pre+1,ret);
			else
				p3 = path[i-1][j];
			p = max(p,p3+1);

		}
		int p4 = 0;
		if(i+1<matrix.size() && matrix[i+1][j]>matrix[i][j])//下
		{
			if(!path[i+1][j])
				p4 = dfs(matrix,path,i+1,j,pre+1,ret);
			else
				p4 = path[i+1][j];
			p = max(p,p4+1);

		}
		path[i][j] = p;
		if(pre+p>ret)
			ret = cur;
	    return p;
		  	
    }
};



//对上面ret更新方式的改进
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

    	int m = matrix.size();
    	if(m == 0)
    		return 0;
    	int n = matrix[0].size();
    	if(n == 0)
    		return 0;
    	vector<vector<int>> path(m,vector<int>(n,0));
    	int ret = 0;
    	for(int i = 0;i < m;i++)
    	{
    		for(int j = 0;j < n;j++)
    		{
    			int temp = dfs(matrix,path,i,j);
    			if(temp > ret)
    				ret = temp;
    		}
    	}
    	return ret;       
    }

    int dfs(vector<vector<int>> &matrix,vector<vector<int>> &path,int i,int j)
    {
		
		int p = 1;
		if(j-1>=0 && matrix[i][j-1]>matrix[i][j])//左
		{
			int p1 = 0;
			if(!path[i][j-1])
				p1 = dfs(matrix,path,i,j-1);
			else
				p1 = path[i][j-1];
			p = max(p,p1+1);

		}
		
		if(j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j])//右
		{
			int p2 = 0;
			if(!path[i][j+1])
				p2 = dfs(matrix,path,i,j+1);
			else 
				p2 = path[i][j+1];
			p = max(p,p2+1);

		}
		
		if(i-1>=0 && matrix[i-1][j]>matrix[i][j])//上
		{   
			int p3 = 0;
			if(!path[i-1][j])
				p3 = dfs(matrix,path,i-1,j);
			else
				p3 = path[i-1][j];
			p = max(p,p3+1);

		}
		
		if(i+1<matrix.size() && matrix[i+1][j]>matrix[i][j])//下
		{
			int p4 = 0;
			if(!path[i+1][j])
				p4 = dfs(matrix,path,i+1,j);
			else
				p4 = path[i+1][j];
			p = max(p,p4+1);

		}
		path[i][j] = p;
	    return p;		  	
    }
};

