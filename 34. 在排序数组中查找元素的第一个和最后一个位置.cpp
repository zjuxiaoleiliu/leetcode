题目描述:

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ret;
        int n = nums.size();
        int first = -1;
        int l = 0;
        int r = n-1;
        while(l<=r)//如果用一个过程，同时找两个边界，当遇到等于目标时左右扫描找边界
        {          //这种算法当数组全等于目标时就退化成线性算法而不是o(logn)算法了
            int mid = l+(r-l)/2;
            if(nums[mid] == target)
            {
                first = mid;//在查找过程中使用一个变量随时跟踪记录信息
                if(mid>l && nums[mid-1] == target)//如果还有左边，并且左边等于目标
                    r=mid-1;
                else//其他情况或者没有左边或者左边的值不等于目标
                    break;
            }
            else if(nums[mid]>target)
                r=mid-1;
            else
                l=mid+1;

        }
        
        int second = -1;
        l = 0;
        r = n-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid] == target)
            {
                second = mid;
                if(mid<r && nums[mid+1] == target)//如果还有右边，并且右边等于目标
                    l=mid+1;
                else//其他情况或者没有右边或者右边的值不等于目标
                    break;
            }
            else if(nums[mid]>target)
                r=mid-1;
            else
                l=mid+1;

        }

        ret.push_back(first);
        ret.push_back(second);

        return ret;
        
    }

};