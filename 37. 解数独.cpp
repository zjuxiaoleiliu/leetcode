题目描述:

编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。



一个数独。



答案被标成红色。

Note:

给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。

/*
玩家需要根据9×9盘面上的已知数字，推理出所有剩余空格的数字，
并满足每一行、每一列、每一个粗线宫（3*3）内的数字均含1-9，不重复。
数独盘面是个九宫，每一宫又分为九个小格。在这八十一格中给出一定的
已知数字和解题条件，利用逻辑和推理，在其他的空格上填入1-9的数字。
使1-9每个数字在每一行、每一列和每一宫中都只出现一次，所以又称“九宫格”。
*/
class Solution {
  
public:
    void solveSudoku(vector<vector<char> > &board) {
        if(board.size() != 9 || board[0].size() != 9)
            return;
        solveSudokuCore(board,0);
    }
    bool solveSudokuCore(vector<vector<char> > &board,int index)
    {
        if(index == 81)
            return true;
      
        int row = index/9;
        int col = index%9;
        if(board[row][col] == '.')
        {
           for(int i = 1; i <= 9; i++)
            {
                board[row][col] = i+'0';
                if(isvalid(board,row,col))
                {
                   bool ret = solveSudokuCore(board,index+1);
                   if(ret)
                       return true;
                }
                board[row][col] = '.';
            }
        }
        else
            return solveSudokuCore(board,index+1);
        
        return false;
    }
     
    bool isvalid(vector<vector<char> > &board,int row,int col)
    {
        
        for(int i = 0; i < 9; i++)
        {
            if(i != col && board[row][col] == board[row][i])
                return false;
            if(i != row && board[row][col] == board[i][col])
                return false;
        }
        for(int i = (row/3)*3; i < (row/3)*3+3;i++)
            for(int j = (col/3)*3; j < (col/3)*3+3; j++)
        {
            if(!(i == row && j == col) && board[row][col] == board[i][j])
                return false;
        }
        return true;
    }
};