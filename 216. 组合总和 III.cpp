找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

    	vector<vector<int>> ret;
    	if(k > 9)
    		return ret;
    	if(n < (1+k)*k/2)
    		return ret;
    	vector<int> temp;
    	combinationSum3Core(1,k,n,0,temp,ret);
    	return ret;    
    }
    void combinationSum3Core(int start,int k,int n,int curSum,vector<int> &temp,vector<vector<int>> &ret)
    {
    	if(temp.size() == k)
    	{
    		if(curSum == n)
    			ret.push_back(temp);
    		return;
    	}
    	for(int i = start;i <= 9;i++)
    	{
    		if(curSum+i > n || 9-i+1 < k-temp.size())//剪枝
    			return;
    		temp.push_back(i);
    		combinationSum3Core(i+1,k,n,curSum+i,temp,ret);
    		temp.pop_back();
    	}

    }
};