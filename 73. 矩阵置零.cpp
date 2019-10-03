题目描述:
Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(m n) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

//思路：因为题目要求我们不能使用额外的空间，要在原地进行，所以除了向有没有更
//巧妙的算法方向思考外，另一个思考的方向是是否可以用原始数组这个容器存储信息
//如果用第二个思路解决问题，我们要注意在覆盖信息之前先保存状态信息

//方法1:这个思路和第二个方法是一样的，但是实现的是错误的，值得注意深思
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {

    	if(matrix.size()==0 || matrix[0].size()==0)
    		return;
    	int m = matrix.size();
    	int n = matrix[0].size();
        int row = -1;//这一行存储列必须置为0的列号
        int col = -1;//这一列存储行必须置为0的行号
        bool found = false;
    	for(int i = 0;i<m;i++)
    	{
    		if(found == true)
    			break;
    		for(int j =0;j<n;j++)
    		{
    			if(matrix[i][j] == 0)
    			{
    				row = i;
    				col = j;
    				found= true;
    				break;
    			}

    		}
    	}

    	if(found == false)
    		return;

    	for(int i =0;i<n;i++)
    		matrix[row][i]=-1;
    	for(int i = 0;i < m;i++)
    		matrix[i][col]=-1;
    	int k = -1;
    	for(int i = 0;i<m;i++)
    	{
    		for(int j = 0;j < n;j++)
    		{
    			if(matrix[i][j] == 0)
    			{
    				matrix[row][j]=j+1;
    				if(i == row)
    					k = i+1;
    				else
    					matrix[i][col] = i+1;
    			}

    		}
    	}

    	for(int i = 0;i < n;i++)
    	{
    		if(matrix[row][i]!=-1)
    		{
    			int colZero = matrix[row][i]-1;
    			if(colZero == col)
    				continue;
    			else
    			{
    				for(int j = 0;j < m;j++)
    				{
    					matrix[j][colZero] = 0;
    				}
    			}

    		}
    	}
        
        matrix[row][col] = k;
    	for(int i = 0;i < m;i++)
    	{
    		if(matrix[i][col]!=-1)
    		{

    			int rowZero = matrix[i][col]-1;
    		    for(int j = 0;j < n;j++)
    		    	matrix[rowZero][j] = 0;
    	
    		}

    	}

    	for(int i = 0;i<n;i++)
    		matrix[row][i]=0;
    	for(int i =0;i<m;i++)
    		matrix[i][col]=0;
        
    }
};




//时间复杂度O(mn)，空间复杂度O(1)
//利用第一行和第一列的空间做记录
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {


    	if(matrix.size()==0 || matrix[0].size()==0)
    		return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool row_flag = false, col_flag = false;        
        //判断第一行和第一列是否有零，防止被覆盖
        for(int i = 0; i < m; i++)
        {
        	if(matrix[i][0] == 0)
        	{
                col_flag = true;
                break;
            }
        }
        for(int i = 0; i < n; i++)
        {
        	if(matrix[0][i] == 0) 
        	{
                row_flag = true;
                break;
            }
        }
        //遍历矩阵，用第一行和第一列记录0的位置
        //第一行第一列原有的0是根据第一行第一列得出的要置行和列为全0的
        //的信息
        for(int i = 1; i < m; i++)
        {
        	for(int j = 1; j < n; j++)
        	{   //根据除了第一行和第一列之外的其他行列得出要置行和列全为0的信息
                if(matrix[i][j] == 0)
                {   //既是存储是否将这一行全置为0的标志信息
                    matrix[i][0] = 0;//也是提前将这一行的第一个元素置为0
                    matrix[0][j] = 0;
                }
            }
        }
        //根据记录清零
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {

            	if(matrix[i][0]==0 || matrix[0][j]==0)
            		matrix[i][j] = 0;
            }           
        }    
        //最后处理第一行
        if(row_flag)
            for (int i = 0; i < n; i++)
                matrix[0][i] = 0;
        if(col_flag)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};


