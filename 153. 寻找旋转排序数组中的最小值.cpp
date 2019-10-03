假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0


提示1：
Array was originally in ascending order. Now that the array 
is rotated, there would be a point in the array 
where there is a small deflection(偏转) 
from the increasing sequence. 
eg. The array would be something like [4, 5, 6, 7, 0, 1, 2].

提示2：
You can divide(划分) the search space into two and see 
which direction to go. 
Can you think of an algorithm which has O(logN) 
search complexity？

提示3：
All the elements to the left of inflection point(拐点)>first element 
of the array.
All the elements to the right of inflection point < first element 
of the array.

class Solution {
public:
    int findMin(vector<int>& nums) {

    	int n = nums.size();
    	if(n == 0)
    		return INT_MAX;
    	if(n == 1)
    		return nums[0];
    	if(nums[0] < nums[n-1])
    		return nums[0];
    	int l = 0;
    	int h = n-1;
    	while(l < h)//这个程序架构的设计让l永远指向前半部分的旋转数组中的元素
        {           //r永远指向后半部分的旋转数组中的元素
        	if(h-l == 1)//由于这里的l,h的二分搜索更新方式，所以这里要手动的做一下判断
        		return nums[h];
			int mid = l+(h-l)/2;
		    if(nums[mid] > nums[l])
		    	l = mid;
		    else if(nums[mid] < nums[h])
		    	h = mid;
	    }
    	return INT_MAX;       
    }
};