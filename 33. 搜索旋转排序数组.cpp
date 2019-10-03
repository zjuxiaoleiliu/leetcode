题目描述:

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

//第一种方法：对要查找的区间分情况对待
class Solution {
public:
    int search(int A[], int n, int target) {

    	int l = 0;
    	int r = n-1;
    	while(l <= r)
    	{
    		int mid = l+(r-l)/2;
    		if(A[mid] == target)
    			return mid;

            if(A[l] <= A[r])//对要查找的区间分情况对待
            {
            	if(A[mid]>target)
            		r=mid-1;
            	else if(A[mid]<target)
            		l=mid+1;
            }
            else
            {//到这一步骤时查找范围至少包含两个元素
            	if(A[mid]>=A[l])
            	{
            		if(target>=A[l] && target<A[mid])
            			r = mid-1;
            		else
            			l=mid+1;

            	}
                
                if(A[mid]<=A[r])
                {
                	if(target>A[mid] && target<=A[r])
                		l = mid+1;
                	else
                		r=mid-1;
                }


            }

    	}

    	return -1;
        
    }
};

 //第二种方法：对要中间位置的元素位于那一段分情况
//缩小查找范围的依据是利用局部有序性按照整个一般区间是否包含查找的元素进行讨论，而不像普通的依据中间点的值
//的判断结果

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l <= r)//围绕缩小查找范围而讨论
        {
            int mid = l+(r-l)/2;
            if(nums[mid] == target)
                return mid;
            //位于前一段时，查找范围[l,r]的前一半[l,mid]天然有序，只要判断出不在这一范围中
            if(nums[l] <= nums[mid])//时定在查找范围[l,r]的另一半中
            {
                if(nums[l] <= target && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {//位于后一段时，查找范围[l,r]的后一半[mid,r]天然有序，只要判断出不在这一范围中
                if(nums[mid] < target && target <= nums[r])//时定在查找范围[l,r]的另一半中
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};