题目描述:

Given an array S of n integers, find three integers in S 
such that the sum is closest to a given number, target.
 Return the sum of the three integers. You may assume that
  each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        
    	int closest = nums[0] + nums[1] + nums[2];
        int diff = abs(closest - target);//循环前的初始化工作
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= int(nums.size() - 3); ++i)
        {
            int left = i + 1, right = nums.size() - 1;
            while(left < right)
            {

                int sum = nums[i] + nums[left] + nums[right];
                int newDiff = abs(sum - target);
                if(diff > newDiff)
                {   
                	if(newDiff == 0)
                		return target;
                    diff = newDiff;
                    closest = sum;
                }
                if(sum < target)
                	++left;
                else
                	--right;               
            }
        }
        return closest;       
    }
};
