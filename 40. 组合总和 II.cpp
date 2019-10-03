题目描述:

Given a collection of candidate numbers ( C ) and a target number ( T ),
 find all unique combinations in C where the candidate numbers sums to T .

Each number in C may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a 1, a 2, … , a k) must be in non-descending order. 
(ie, a 1 ≤ a 2 ≤ … ≤ a k).
The solution set must not contain duplicate combinations.

For example, given candidate set10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
//和set2的思路一样，从原始的起始点开始一层一层的产生一个个的组合，每一个组合都是由一个前缀+一个元素构成，我们都是在合法
//前缀基础上产生组合的，所以我们产生的组合不会发生遗漏，同一个前缀加不同的元素构成的组合当然不同，
//由于前缀不同，由不同的前缀产生的组合之间更不同了，所以这样产生的组合不会重合，
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {

    	vector<vector<int>> ret;
    	sort(num.begin(),num.end());
    	vector<int> temp;
    	int curSum = 0;
    	combinationSum2Core(num,0,ret,temp,curSum,target);
    	return ret;        
    }


    void combinationSum2Core(vector<int> &num,int index,vector<vector<int>> &ret,vector<int> &temp,int &curSum,int target)
    {
    	if(index == num.size())
    		return;

    	for(int i = index;i < num.size();i++)
    	{
            if(i != index && num[i] == num[i-1])//每一次产生的前缀都是唯一的，满足给定的条件时，以这个
            	continue;                       //前缀为基础的dfs就可以停止了

    		curSum += num[i];
    		if(curSum > target)
    		{
    			curSum-=num[i];
    			return;//剪枝
    		}
    		else if(curSum == target)
    		{
    			temp.push_back(num[i]);
    			ret.push_back(temp);
    			temp.pop_back();
    			curSum-=num[i];
    			return;//剪枝
    		}
    		else
    		{
    			temp.push_back(num[i]);
    			combinationSum2Core(num,i+1,ret,temp,curSum,target);
    			temp.pop_back();
    			curSum-=num[i];
    	    }
    			
    	}

    }

    
};