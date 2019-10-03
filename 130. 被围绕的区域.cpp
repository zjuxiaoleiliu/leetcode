题目描述:

给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 
任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。


//思路：从边界上的'O'能够到达的所有的'O'都是不能被包围的
//一个技巧：不用额外的开辟一个空间用来表示标志信息，将标志信息
//原地保存在原数组中，为了不覆盖原有的信息，只需要将标志信息用一个特殊的
//原数组中没有出现过的字符来体现

class Solution {
public:
    void solve(vector<vector<char>> &board) {

    	if(board.size()==0 || board[0].size()==0)
    		return;

    	for(int i = 0;i<board.size();i++)
    	{  
  
    		solveCore(board,i,0);
    		solveCore(board,i,board[0].size()-1);

    	}

    	for(int i = 0;i<board[0].size();i++)
    	{
    		solveCore(board,0,i);
    		solveCore(board,board.size()-1,i);

    	}

    	for(int i = 0;i<board.size();i++)
    	{
    		for(int j = 0;j < board[0].size();j++)
    		{
    			if(board[i][j] == 'O')
    				board[i][j]='X';
    			if(board[i][j] == '*')
    				board[i][j]='O';
    		}
    	}
       
    }

    void solveCore(vector<vector<char>> &board,int i,int j)
    {
    	if(board[i][j] == 'O')
    	{
    		board[i][j]='*';
    		if(j>0)
    			solveCore(board,i,j-1);
    		if(j<board[0].size()-1)
    			solveCore(board,i,j+1);
    		if(i>0)
    			solveCore(board,i-1,j);
    		if(i<board.size()-1)
    			solveCore(board,i+1,j);
    	}

    }
};