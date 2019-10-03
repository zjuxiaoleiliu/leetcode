给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口k内的数字。滑动窗口每次只向右移动一位。

返回滑动窗口最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
注意：

你可以假设 k 总是有效的，1 ≤ k ≤ 输入数组的大小，且输入数组不为空。

进阶：

你能在线性时间复杂度内解决此题吗？


提示1：
How about using a data structure such as deque (double-ended queue)?
提示2：
The queue size need not be the same as the window’s size.
提示3：
Remove redundant elements and the queue should store only elements 
that need to be considered.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ret;
    	int n = nums.size();
    	if(n == 0 || k <= 0 || n < k)
    	    return ret;
    	deque<int> q;
    	for(int i = 0;i < k;i++)
    	{
    		while(!q.empty() && nums[i] >= nums[q.back()])
    			q.pop_back();
    		q.push_back(i);
    	}
    	for(int i = k;i < n;i++)
    	{
    		ret.push_back(nums[q.front()]);
    		if(q.front() < i-k+1)
    			q.pop_front();
    		while(!q.empty() && nums[i] >= nums[q.back()])
    			q.pop_back();
    		q.push_back(i);
    	}
    	ret.push_back(nums[q.front()]);
    	return ret;
    }
};
