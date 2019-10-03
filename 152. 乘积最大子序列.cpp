给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

class Solution {
public:
    int maxProduct(vector<int>& nums) {

    	int n = nums.size();
    	if(n == 1)
    		return nums[0];
    	int ret = nums[0];
    	int curMax = nums[0];
    	int curMin = nums[0];
    	for(int i = 1;i < n;i++)
    	{
    		int temp1 = min(nums[i]*curMin,nums[i]*curMax);
    		int temp2 = max(nums[i]*curMin,nums[i]*curMax);
    		curMin = min(nums[i],temp1);
    		curMax = max(nums[i],temp2);
    		ret = max(curMax,ret);
    	}
    	return ret;       
    }
};