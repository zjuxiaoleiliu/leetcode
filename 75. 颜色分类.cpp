题目描述:
Given an array with n objects colored red(红), white(白) or blue(蓝),
 sort them so that objects of the same color are adjacent, 
 with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent 
the color red, white, and blue respectively.

Note: 
You are not suppose to use the library s sort function for this problem.

click to show follow up.

Follow up: 
A rather straight forward solution is a two-pass algorithm(两趟算法) using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, 
then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

//基于partation思想,小于1的数放在左边，大于1的数放在右边，等于1的数不动
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int zero = -1;//已排好的边界
        int two = n;//尾指针对运用
        int i = 0;
        while(i<two)
        {
            if(nums[i] == 0)
            {
                swap(nums[++zero],nums[i]);
                i++;
            }
            else if(nums[i] == 2)
            {
                swap(nums[i],nums[--two]);
            }
            else 
                i++;
        }
        
    }
};