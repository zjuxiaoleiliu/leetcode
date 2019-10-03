题目描述

判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。


上图是一个部分填充的有效的数独。

数独部分空格内已填入了数字，空白格用 '.' 表示。

示例 1:

输入:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: true
示例 2:

输入:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: false
解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
说明:

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
给定数独序列只包含数字 1-9 和字符 '.' 。
给定数独永远是 9x9 形式的。


/*
玩家需要根据9×9盘面上的已知数字，推理出所有剩余空格的数字，
并满足每一行、每一列、每一个粗线宫（3*3）内的数字均含1-9，不重复。
数独盘面是个九宫，每一宫又分为九个小格。在这八十一格中给出一定的
已知数字和解题条件，利用逻辑和推理，在其他的空格上填入1-9的数字。
使1-9每个数字在每一行、每一列和每一宫中都只出现一次，所以又称“九宫格”。
*/


//方法1:递归解决方案
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {

        if(board.size()!=9 || board[0].size()!=9)
        	return false;
    	return isValidSudokuCore(board,0);
    
    }

    bool isValidSudokuCore(vector<vector<char> > &board,int index)
    {
        if(index == 81)
            return true;
      
        int row = index/9;
        int col = index%9;
        if(board[row][col] != '.')
        {
           if(isvalid(board,row,col))
           	return isValidSudokuCore(board,index+1);
           else
           	return false;
        }
        else
            return isValidSudokuCore(board,index+1);
      
        
        return false;
    }
     
    bool isvalid(vector<vector<char> > &board,int row,int col)
    {

        if(board[row][col]-'0'>9 || board[row][col]-'0'<1)
        	return false;
        for(int i = 0; i < 9; i++)
        {
            if(i != col && board[row][col] == board[row][i])
                return false;
            if(i != row && board[row][col] == board[i][col])
                return false;
        }
        for(int i = (row/3)*3; i < (row/3)*3+3;i++)
        {
            for(int j = (col/3)*3; j < (col/3)*3+3; j++)
            {
                if(!(i == row && j == col) && board[row][col] == board[i][j])
                    return false;
            }
    }
        return true;
    }



};

//方法2：上面方案的循环实现

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) 
    {

        if(board.size()!=9 || board[0].size()!=9)
        	return false;

        for(int row = 0; row < 9; row++)
        {
        	for(int col = 0; col < 9; col++)
        	{   

        		if(board[row][col] == '.')
        			continue;
        		else
        		{
        			if(board[row][col]-'0'>9 || board[row][col]-'0'<1)
        				return false;
        		    for(int i = 0; i < 9; i++)
        		    {
        		    	if(i != col && board[row][col] == board[row][i])
        		    		return false;
        		    	if(i != row && board[row][col] == board[i][col])
        		    		return false;
        		    }

                    for(int i = (row/3)*3; i < (row/3)*3+3;i++)
                    {
                    	for(int j = (col/3)*3; j < (col/3)*3+3; j++)
                    	{
                    		if(!(i == row && j == col) && board[row][col] == board[i][j])
                    			return false;
            
                        }
                    }

                }

            }

        }

                     
        return true;
    
    }


};

//方法三：利用辅助数组

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
 
        int rows[9][9]={0},cols[9][9]={0},cube[9][9]={0};//第二维下标表示这个数组在当前是否已经出现过
         
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                char num = board[i][j]; 
                if(num != '.')     
                {

                  if(num-'0'>9 || num-'0'<1)
                        return false;
                    if(rows[i][num-'1'] == 1)   //判断当前行
                        return false;
                    else
                        rows[i][num-'1']++;
                     
                    if(cols[j][num-'1'] == 1)   //判断当前列
                        return false;
                    else
                        cols[j][num-'1']++;
                     
                    if(cube[3*(i/3)+j/3][num-'1'] == 1)     //判断当前块
                        return false;
                    else
                        cube[3*(i/3)+j/3][num-'1']++;                  
                }
            }
        }
        return true;
    }
};