题目描述:

Given an array S of n integers, are there elements a, b, c, 
and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:

Elements in a quadruplet (a,b,c,d) must be in non-descending order. 
(ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
//方法1：set去重
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target)
    {

    	set<vector<int>> ret;
        sort(nums.begin(), nums.end());

        for(int i = 0; i <= (int)(nums.size() - 4); ++i) 
        {

            for(int j = i + 1; j <= (int)(nums.size() - 3); ++j)
            {

                int left = j + 1, right = nums.size() - 1;
                while(left < right) 
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum < target)
                    	++left;
                    else if (sum > target)
                    	--right;
                    else
                    {
                    	vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                        ret.insert(temp);
                        ++left; 
                        --right;
                    } 
                }
            }
        }
        return vector<vector<int>>(ret.begin(), ret.end());
        
    }
};

//方法2：一种比较正统的做法吧，手动进行去重复处理
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target)
    {

    	vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        for(int i = 0; i <= int(nums.size() - 4); ++i) 
        {
             //元素是用一个少一个，找4元组，4元组的每一个位置的取值都保证不重复
        	if(i > 0 && nums[i] == nums[i - 1])//第一次用过后,下一次这个位置不再使用防止重复 
        		continue;

            for(int j = i + 1; j <= int(nums.size() - 3); ++j)
            {
                //第一次总是没问题的
                if(j > i + 1 && nums[j] == nums[j - 1]) 
                	continue;
                //第一次总是没问题的
                int left = j + 1, right = nums.size() - 1;

                while(left < right) 
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum < target)
                    	++left;
                    else if (sum > target)
                    	--right;
                    else
                    {
                    	vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                        ret.push_back(temp);
                        ++left; 
                        --right;
                        while(left<right && nums[left]==nums[left-1]) ++left;
                        while(left<right && nums[right]==nums[right+1]) --right;

                    } 
                }
            }
        }

        return ret;
        
    }
};