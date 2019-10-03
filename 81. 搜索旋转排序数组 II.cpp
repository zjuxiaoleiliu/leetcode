题目描述:

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
示例 2:

输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
进阶:

这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l=0;
        int r=n-1;
        while(l<=r)
        {

            int mid=l+(r-l)/2;
            if(nums[mid]==target)
                return true;
            if(nums[l]==nums[mid] && nums[mid]==nums[r])//此时无法判断出mid
            {            //到底是可以分配到旋转数组的那一段中，进而也就无法
                l++;    //使用二分搜索缩小搜索的范围
                r--;
            //因为经过上面的判断A[mid]!=target，所以A[l],A[r]都可以从搜索范围中排除掉
            }
            else//下面的情况是能够确定mid位于旋转数组的那一段的情况
            {   //能够分配到前半段
                if(nums[l]<=nums[mid])//左边有序
                {
                    if(nums[l]<=target && target<nums[mid])
                        r=mid-1;
                    else
                        l=mid+1;
                }
                //能够分配到后半段
                if(nums[mid]<=nums[r])//右边有序
                {
                    if(nums[mid]<target && target<=nums[r])
                        l=mid+1;
                    else
                        r=mid-1;
                }

            }
           
        }
         
        return false;
    }
};

class Solution {
public:
    bool search(int A[], int n, int target) {

        int l = 0;
        int r = n-1;
        while(l <= r)
        {

        	while(l<r && A[l+1]==A[l]) l++;
            while(l<r && A[r-1]==A[r]) r--;

            int mid = l+(r-l)/2;
            if(A[mid] == target)
                return true;           
            if(A[l] <= A[mid])
            {
                if(A[l] <= target && target < A[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if(A[mid] < target && target <= A[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }

        }

        return false;

    }
};

