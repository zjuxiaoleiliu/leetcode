题目描述:

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise顺时针方向).

Follow up:
Could you do this in-place?
//方法1：最外圈到最里圈，一层一层的转
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {

    	if(matrix.size()==0 || matrix[0].size()!=matrix.size())
    		return;

        int n=matrix.size();
        for(int i=0;i<n/2;i++)
        {
            for(int j=i;j<n-1-i;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];//根据位移不变性找坐标
                matrix[n-1-j][i]= matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=temp;
            }
        }        
    }
};
//解法2：把矩阵旋转90度是按照一定的规则把行变成列(把第一行变为最后一列，把第二行
//变为倒数第二列，把第三行变为倒数第三列。。。)，而转置为：
//把第一行变为第一列，把第二行变为第二列，把第三行变为第三列，。。。
//可以发现把矩阵旋转90度和把矩阵转置这两种操作具有某种相似性
//一次完成不了可以分步完成。先把原矩阵转置(矩阵转置也是按照一定的规则把行变成列
//然后再把列调整成满足矩阵旋转90度的规则要求)，然后沿Y轴对称(翻转列)就行了
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) 
    {

    	if(matrix.size()==0 || matrix[0].size()!=matrix.size())
    		return;
    	int n = matrix.size();
        //先转置,公式：a[i][j] = a[j][i]
        for(int i=0;i<n;i++)//矩阵转置相当于沿着对角线翻转
        {   //操作不能做到重复
        	for(int j=i+1;j<n;j++)//上三角
        	{
        		int temp = matrix[i][j];
        		matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        //再沿着Y轴对称调整
        for(int j=0;j<n/2;j++)//n/2理解成长度
        {
        	for(int i=0;i<n;i++)
        	{
        		int temp = matrix[i][j];
        		matrix[i][j] = matrix[i][n-1-j];//利用位移不变性找坐标点
        		matrix[i][n-1-j] = temp;
            } 
        } 
    }

};