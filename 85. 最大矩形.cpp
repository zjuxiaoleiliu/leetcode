题目描述:

给定一个仅包含0和1的二维二进制矩阵，
找出只包含1的最大矩形，并返回其面积。

示例:

输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
输出: 6

//思路：把每一行看成求直方图中最大矩形面积问题
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        
        if(matrix.size()==0 || matrix[0].size()==0)
        	return 0;
    	int row=matrix.size();
        int column=matrix[0].size();
        vector<int> height(column,0);
        int ret=0;
        for(int i=0;i<row;++i)
        {
        	for(int j=0;j<column;++j)
        	{   
                //求当前第i行往上连续1的个数，不连续就置为0
                //高度必须从底部起开始算起
        		if(matrix[i][j]=='1')//一票否决
                    height[j]++;
                else
                    height[j]=0;
            }
            ret=max(ret,largestRectangleArea(height));
        }
        return ret;       
    }

    int largestRectangleArea(vector<int> &height)
    { 
        int ret = 0;  
        stack<int> s;  
        int i = 0;
        int n = height.size();
        while(i < n)//流式处理 
        { 
            if(s.empty() || height[s.top()] <= height[i]) 
                s.push(i++);  
            else
            {
                int h = height[s.top()];
                s.pop(); //s.top()前面如果有元素的话，一定比它小，如果出现              
                ret = max(ret,(s.empty()?i:i-s.top()-1)*h);//下标中断，那一定是比它高  
            }                             //因为比它高，后面遇到低的，就弹出了
        }                                 //如果比s.top()低，按照入栈的顺序，肯定
        while(!s.empty())                 //是先弹出s.top(),再弹出s.top()前面比它低的
        { 
            int h = height[s.top()];
            s.pop(); 
            ret = max(ret,(s.empty()?n:n-s.top()-1)*h);  
        }  
        return ret; 
    } 

};


