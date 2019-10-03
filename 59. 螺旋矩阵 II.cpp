题目描述:

Given an integer n, generate a square matrix filled with elements
from 1 to n^2 in spiral order.//按螺旋顺序排列

For example,
Given n =3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	
    	vector<vector<int>> ret(n,vector<int>(n));
    	if(n<1)
    		return ret;
    	int val = 1;
    	for(int i = 0;i<n/2;i++)
    	{
    		for(int j = i;j<=n-1-i;j++)
    		{
    			ret[i][j]=val;
    			val++;
    		}
    		for(int j = i+1;j<=n-1-i;j++)
    		{
    			ret[j][n-1-i]=val;
    			val++;
    		}
    		for(int j = n-1-i-1;j>=i;j--)
    		{
    			ret[n-1-i][j]=val;
    			val++;
    		}
    		for(int j =n-1-i-1;j>=i+1;j--)
    		{
    			ret[j][i]=val;
    			val++;
    		}   
    	}
    	if(n%2==1)
    		ret[n/2][n/2]=val;
    	return ret;        
    }
};

