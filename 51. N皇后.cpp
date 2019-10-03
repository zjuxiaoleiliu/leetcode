题目描述:

The n-queens puzzle is the problem of placing n queens on an n×n 
//使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上
chessboard such that no two queens attack each other.


Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens placement, 
where'Q'and'.'both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
    	vector<vector<string>> ret;
        vector<string> temp(n, string(n, '.'));
        solveNQueensCore(ret,0,temp,n);
        return ret;
    }


    bool isValid(vector<string> &temp, int row, int col, int n)
    {

    	for(int i = 0; i < row;i++)
    	{
    		if(temp[i][col] == 'Q')
    			return false;
        }
    
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0;i--,j--)
        {
        	if (temp[i][j] == 'Q')
        		return false;
        }

        for(int i = row - 1, j = col + 1; i >= 0 && j < n;i--,j++)
        {
        	if (temp[i][j] == 'Q')
        		return false;
        }

        return true;

    }

    void solveNQueensCore(vector<vector<string>> &ret,int row,vector<string> &temp,int n)
    {
    	if(row == n)
    	{
    		ret.push_back(temp);
    		return;
        }

        for(int col = 0; col < n;col++)//遍历递归这一行的n种摆法
        {

        	if(isValid(temp,row,col,n))
        	{
        		temp[row][col] = 'Q';
                solveNQueensCore(ret,row + 1,temp,n);
                temp[row][col] = '.';
            }

        }

    }

};
