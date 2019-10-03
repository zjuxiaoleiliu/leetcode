给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。

数学表达式如下:

如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。
说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。

示例 1:

输入: [1,2,3,4,5]
输出: true
示例 2:

输入: [5,4,3,2,1]
输出: false

//贪心策略
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

    	int n = nums.size();
    	if(n < 3)
    		return false;
    	int first = INT_MAX;//占位符的初始化符合从左往右进行讨论的需要
        int second = INT_MAX;//相当于占位符的作用
        int cnt = 0;
        for(int i = 0;i < n;i++) 
        {
        	if(nums[i] < first)//通过if条件语句的设计使比较从左往右进行展开讨论
        		first = nums[i];
        	else if(nums[i] > first && nums[i] <second)
        		second = nums[i];
        	else if(nums[i] > second)
        		return true;            
        }
        return false;        
    }
};