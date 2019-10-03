题目描述:

Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
 
        vector<int> ret;
    	if(matrix.size()==0 || matrix[0].size() == 0)
    		return ret;
    	int m = matrix.size();
    	int n = matrix[0].size();    
        int circles=min(m,n)/2;
        for(int i=0;i<circles;i++)
        {
            for(int j=i;j<=n-1-i;j++)
                ret.push_back(matrix[i][j]);
            for(int j=i+1;j<=m-1-i;j++)
                ret.push_back(matrix[j][n-1-i]);
            for(int j=n-1-i-1;j>=i;j--)
                ret.push_back(matrix[m-1-i][j]);
            for(int j=m-1-i-1;j>=i+1;j--)
                ret.push_back(matrix[j][i]);
        }

        if(min(m,n)%2)
        {          
            if(m>n)
            {          
               for(int j=circles;j<=m-1-circles;j++)
                  ret.push_back(matrix[j][circles]);
            }
            else
            {          
            	for(int j=circles;j<=n-1-circles;j++)
            		ret.push_back(matrix[circles][j]);
            }
 
        }

        return ret;
    }
};
