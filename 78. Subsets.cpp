题目描述:

Given a set of distinct integers, S, return all possible subsets.

Note:
                                //非下降顺序
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example,
If S =[1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
//方法1：动态规划解法
//动态规划：如何分解整个问题？递推公式是怎么样的？得到小问题的解后
//如何根据递推公式得到整个问题的解？
//经典的组合问题解决方案：分解整个问题：组合中是否包含元素i，不包含元素i的组合，包含元素i的组合
//整个问题所有的组合为：不包含元素i的组合+包含元素i的组合，而包含元素i的所有组合等于
//将元素i加入到不包含元素i的所有组合的每一个组合中
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {

    	vector<vector<int>> ret;
    	vector<int> empty;
    	ret.push_back(empty);
    	sort(S.begin(),S.end());
    	for(int i = 0;i < S.size();i++)
    	{   
    		int size = ret.size();
    		for(int j = 0;j < size;j++)
    		{
    			vector<int> temp = ret[j];
    			temp.push_back(S[i]);
    			ret.push_back(temp);
    		}
    	}

    	//下面的这段代码是为了使得子集之间也有顺序：按照元素个数，子集个数相同时按照
        //sort(ret.begin(),ret.end());//子集首元素大小
        //vector<vector<int>> result;
        //for(int i=0;i<=S.size();i++)
        /*{
            for(int j=0;j<ret.size();j++)
                if(ret[j].size()==i)
                    result.push_back(ret[j]);
          }*/
        //return ret;
    	return ret;       
    }
};


//方法2：按照数学中组合的思想，一个位置的处理情况：我们选取，我们不选取，
//我们遍历所有位置的处理情况，即得到所有的组合，这可以用经典的递归
//解决方案

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) 
    {

    	vector<vector<int>> ret;
    	vector<int> temp;
        sort(S.begin(),S.end());
    	subsetsCore(S,0,ret,temp);
    	return ret;
        
    }

    void subsetsCore(vector<int>&S,int index,vector<vector<int>>&ret,vector<int>&temp)
    {
    	if(index == S.size())
        {
            ret.push_back(temp);
    		return;
    	}
   
        temp.push_back(S[index]);
        subsetsCore(S,index+1,ret,temp);
    	temp.pop_back();
    	subsetsCore(S,index+1,ret,temp);
 
    }
};