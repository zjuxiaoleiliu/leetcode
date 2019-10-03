题目描述:

Find the contiguous subarray within an array 
(containing at least one number) which has the largest sum.

For example, given the array[−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray[4,−1,2,1]has the largest sum =6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide 
and conquer approach, which is more subtle.
//解法1：动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int max = nums[0];
        int cur = nums[0];
        for(int i =1;i<n;i++)
        {
            if(cur<0)
                cur = nums[i];
            else
                cur = cur+nums[i];
            if(cur>max)
                max = cur;
        }
        return max;        
    }
};