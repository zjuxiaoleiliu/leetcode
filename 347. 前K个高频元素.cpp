给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
说明：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

class Solution {
public:
	struct cmp//定义一个可调用类型functional
	{
	    bool operator()(const pair<int,int> &lhs,const pair<int,int> &rhs)//定义一个最小堆
	    {
	        return lhs.second > rhs.second;
	    }                           
    };                           
    vector<int> topKFrequent(vector<int>& nums, int k) {

    	vector<int> ret;
    	int n = nums.size();
    	if(k<1 || n<k)
    		return ret;
    	map<int,int> m;
    	for(int i = 0;i < n;i++)
    	{
    		if(m.find(nums[i]) == m.end())
    			m[nums[i]] = 1;
    		else
    			m[nums[i]]++; 
    	}
    	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
    	for(auto iter = m.begin();iter!=m.end();iter++)
    	{
    		if(q.size() < k)
    			q.push(*iter);
    		else
    		{
    			pair<int,int> temp = q.top();
    			if(iter->second > temp.second)
    			{
    				q.pop();
    				q.push(*iter);			
    			}
    		}
    	}
    	if(q.size() < k)
    		return ret;
    	while(!q.empty())
    	{
    		ret.push_back(q.top().first);
    		q.pop();
    	}
    	return ret;        
    }
};