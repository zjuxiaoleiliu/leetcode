题目描述:

Given an index k, return the k th row of the Pascal s triangle.

For example, given k = 3,
Return[1,3,3,1].
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
Note: 
Could you optimize your algorithm to use only O(k) extra space?
//递推公式为：dp[i][j] = dp[i-1][j-1]+dp[i-1][j]
//解法1：从左向右计算,对于更新过程中可能会覆盖以后要用到的值，我们在覆盖之前用一个变量
//保存
class Solution {
public:
    vector<int> getRow(int rowIndex) {

    	vector<int> vec;
    	if(rowIndex<0)
    		return vec;
    	vector<int> ret(rowIndex+1,1);

    	for(int i = 2;i<=rowIndex;i++)
    	{
    		int pre = 1;
    		for(int j = 1;j<i;j++)
    		{
    			int temp = ret[j];
    			ret[j]=pre+ret[j];
    			pre = temp;
    		}
    		
    	}

    	return ret;
        
    }
};

//解法2：递推公式为：dp[i][j] = dp[i-1][j-1]+dp[i-1][j]
//从递推公式我们可以知道如果按照从右向左更新，就不会产生覆盖未来还会用到的值的问题

class Solution {
public:
    vector<int> getRow(int rowIndex) {

    	vector<int> vec;
    	if(rowIndex<0)
    		return vec;
    	vector<int> ret(rowIndex+1,1);

    	for(int i = 2;i<=rowIndex;i++)
    	{
    		for(int j =i-1;j>=1;j--)
    		{
    			ret[j]=ret[j-1]+ret[j];
    		}
    		
    	}

    	return ret;
        
    }
};
