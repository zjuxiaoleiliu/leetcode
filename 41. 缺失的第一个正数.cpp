题目描述:

Given an unsorted integer array, find the first missing positive integer.

For example,
Given[1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
//以原数组原地作为一个哈希表，把元素放到它该放到的位置上，
//这里数组下标可以携带信息，数组元素要注意保存合理的值
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 0)
            return 1;  
        int i = 0;
        while(i < n)//循环目的：把数组元素中范围在1-n之间的整数放在正确的位置上
        {
            if(nums[i] <= 0)
                i++;
            else
            {   //如果是正数，并且还没有没有放在正确的位置上
                if(nums[i]<=n && nums[i]!=i+1 && nums[nums[i]-1]!=nums[i])
                {
                    swap(nums[i], nums[nums[i]-1]);//有可能把当前位置后边需要判断的数交换到这里，所以
                }                        //i不能递增
                else
                    i++;                
            }
        } 
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != i+1)
            {
                return i+1;
            }
        }
        return n+1;
    }
};