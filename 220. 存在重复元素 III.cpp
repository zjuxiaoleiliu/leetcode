给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，
使得 nums[i] 和 nums[j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。

示例 1:

输入: nums = [1,2,3,1], k = 3, t = 0
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1, t = 2
输出: true
示例 3:

输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false

//方法1：常规思路,暴力法
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

    	int n = nums.size();
    	if(n < 2)
    		return false;
    	for(int i = 0;i < n;i++)
    	{
    		for(int j = i+1;j < n && j-i<=k;j++)
    			if(abs(nums[i]-nums[j])<=t)
    				return true;
    	}
    	return false;       
    }
};





// 利用set红黑树查找速度提高
// 利用set 作为滑动窗口，用set的Lower_bound()函数找到合适值则return true
// 滑动窗口+set。对于含绝对值的区间问题。
// （其一）因为set中必须存储值a，它又位于绝对值中，所以必须拆开考虑。
// |b - a| <= t =>-t <= b - a <= t =>a <= b + t &&a >= b-t
// （其二）auto iter = std::set::lower_bound(value=x);
// 返回指向首个比较不小于值 x 的元素的迭代器。
// （其三）是否有不用拆开绝对值的方法？

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

    	int n = nums.size();
    	if(n < 2 || k < 0)
    		return false;
        set<long> s;
        for(int i = 0; i < n; i++) 
        {
        	if(i > k)
        		s.erase(nums[i-k-1]);
            auto it = s.lower_bound(nums[i] - long(t));//a >= b - t
                            //*it <= nums[i] + long(t)由于怕溢出，写成下面的形式
            if(it!= s.end() && *it - nums[i] <= t)//a <= b + t 
            	return true;
            s.insert(nums[i]);
        }        
        return false;
    }
};




