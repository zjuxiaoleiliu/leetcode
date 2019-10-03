题目描述:

Follow up for N-Queens problem.

Now, instead outputting board configurations,
return the total number of distinct solutions.



class Solution {
public:
    int totalNQueens(int n)
    {
    	int sum = 0;//如果用二维数组表示棋盘的话，用vector<vector<bool>>
        vector<int> temp;//一维数组表示棋盘，下标代表行，存储的元素代表此行(对应于这个下标行)放置皇后的列的下标
        for(int i = 0;i < n;i++)
        	temp.push_back(i);
        totalNQueensCore(0,temp,sum);
        return sum;
    }


    bool isValid(vector<int> &temp, int row)
    {

    	for(int i = 0; i < row;i++)
    	{   //由于我们这里的棋盘放置已经保证了放置的皇后不同行，不同列，所以这里只检验
    		if(abs(row-i) == abs(temp[row]-temp[i]))//是否在同一斜线上
    			return false;
    	}

        return true;

    }

    void totalNQueensCore(int row,vector<int> &temp,int &sum)
    {
    	if(row == temp.size())
    	{
    		sum++;
    		return;
        }

        for(int index = row; index < temp.size();index++)//遍历递归这一行的所有可能的摆法
        {

        	swap(temp[row],temp[index]);
        	if(isValid(temp,row))
                totalNQueensCore(row + 1,temp,sum);
        	swap(temp[row],temp[index]);
       

        }

    }

};


