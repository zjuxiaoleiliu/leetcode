题目描述:

给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {

    	if(board.size()==0 || board[0].size()==0)
    		return false;
    	vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
    	for(int i = 0;i < board.size();i++)
    	{
    		for(int j =0;j<board[0].size();j++)
    		{
    			if(existCore(board,visited,word,0,i,j))
    				return true;
    		}
    	}
    	return false;      
    }

    bool existCore(vector<vector<char> > &board,vector<vector<bool>> &visited,string word,int index,int i,int j)
    {

    	if(index == word.size())
    		return true;
    	else
    	{
    		if(i==board.size() || i<0 || j==board[0].size() || j<0 || board[i][j] != word[index] || visited[i][j]==true)
    			return false;
    		else
    		{
    			visited[i][j] = true;
    			bool ret = existCore(board,visited,word,index+1,i,j-1) ||  existCore(board,visited,word,index+1,i-1,j) ||
    			           existCore(board,visited,word,index+1,i,j+1) ||  existCore(board,visited,word,index+1,i+1,j);
    			visited[i][j] = false;
    			return ret;    			          
    		}
    	}
    }
};

