给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:

输入: [3,0,1]
输出: 2
示例 2:

输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?


//和只有一个数只出现一次，其他的数都出现了两次思路几乎一样
class Solution {
public:
    int missingNumber(vector<int>& nums) {

    	int n = nums.size();
    	int ret = n;
    	for(int i = 0;i < n;i++)
    		ret = ret^i^nums[i];
    	return ret;
        
    }
};