给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。

示例 1:

输入: [0,1,2,4,5,7]
输出: ["0->2","4->5","7"]
解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
示例 2:

输入: [0,2,3,4,6,8,9]
输出: ["0","2->4","6","8->9"]
解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

    	vector<string> ret;
    	int n = nums.size();
    	if(n == 0)
    		return ret;
    	if(n == 1)
        {
        	ret.push_back(to_string(nums[0]));
        	return ret;
        }

        int left = 0;
        for(int i = 1;i < n;i++)
        {
        	if(nums[i]!=nums[i-1]+1)//思考何时触发一个区间的完成
        	{
        		if(i-1 == left)
        			ret.push_back(to_string(nums[left]));
        		else
        			ret.push_back(to_string(nums[left])+"->"+to_string(nums[i-1]));
        		left = i;     		
        	}
        }
        if(left == n-1)
        	ret.push_back(to_string(nums[left]));
        else
        	ret.push_back(to_string(nums[left])+"->"+to_string(nums[n-1]));
        return ret;   		      
    }
};