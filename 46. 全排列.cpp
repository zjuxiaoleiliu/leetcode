题目描述:

给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]


class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
    	
        vector<vector<int>> ret;
    	permuteCore(num,0,ret);
    	return ret;       
    }

    void permuteCore(vector<int> &num,int index,vector<vector<int>> &ret)
    {
    	if(index == num.size())
    	{
    		ret.push_back(num);
    		return;
    	}

    	else
    	{
    		for(int i = index;i<num.size();i++)
    		{
    			swap(num[index],num[i]);
    			permuteCore(num,index+1,ret);
    			swap(num[index],num[i]);
    		}
    	}
    }
};

