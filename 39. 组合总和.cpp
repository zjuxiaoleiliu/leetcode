题目描述:

Given a set of candidate numbers ( C ) and a target number ( T ),
find all unique combinations in C where the candidate numbers sums to T .

The same repeated number may be chosen from C unlimited number of times.

Note:

All numbers (including target) will be positive integers.
                                                         //非降序
Elements in a combination (a 1, a 2, … , a k) must be in non-descending order. 
(ie, a 1 ≤ a 2 ≤ … ≤ a k).
The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7and target 7, 
A solution set is: 
[7]
[2, 2, 3]


//前缀+一个元素，一层一层的产生，同一前缀加一个不同的元素，不同前缀之间由于前缀不同自然加一个元素产生的
//一定不同
//其实本质还是枚举一个前缀下一个位置的能取值的所有情况
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {

    	vector<vector<int>> ret;
    	sort(candidates.begin(),candidates.end());
    	vector<int> temp;
    	int curSum = 0;
    	combinationSumCore(candidates,0,ret,temp,curSum,target);
    	return ret;        
    }


    void combinationSumCore(vector<int> &candidates,int index,vector<vector<int>> &ret,vector<int> &temp,int &curSum,int target)
    {
    	if(index == candidates.size())
    		return;

    	for(int i = index;i < candidates.size();i++)
    	{
           
    		curSum += candidates[i];
    		if(curSum > target)
    		{
    			curSum-=candidates[i];
    			return;//剪枝
    		}
    		else if(curSum == target)
    		{
    			temp.push_back(candidates[i]);
    			ret.push_back(temp);
    			temp.pop_back();
    			curSum-=candidates[i];
    			return;//剪枝
    		}
    		else
    		{
    			temp.push_back(candidates[i]);
    			combinationSumCore(candidates,i,ret,temp,curSum,target);
    			temp.pop_back();
    			curSum-=candidates[i];
    	    }
    			
    	}

    }

    
};


