给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。

示例 1:

输入: [3,2,3]
输出: [3]
示例 2:

输入: [1,1,1,3,3,2,2,2]
输出: [1,2]


提示1：
How many majority elements could it possibly have? 
Do you have a better hint? Suggest it!



//摩尔投票法
/*
说白了就是不同元素之间的抵消(可以直观的认为不同元素之间的抵消符合交换律和结合律)，最后剩下的就是要求的目标
针对本题，元素个数超过⌊ n/3 ⌋ 次的元素，根据定义我们可以知道这样的数最多有两个，假设数组中元素最多的元素为x,第二多的
为y,
既然抵消符合交换律和结合律，我们不妨将所有的元素x集中到一个集合A中，所有的元素y集中到一个集合B中，
所有既不等于x也不等于y的元素集中到一个集合C中， 
A，C，B，抵消C,如果存在两个次数多于 ⌊ n/3 ⌋的元素，那么最后能把C抵消完，并且集合A和集合B都会剩下元素
如果数组中只存在一个次数多于 ⌊ n/3 ⌋的元素，那么所有的这个元素放在一个集合A中(集合A的大小超过 ⌊ n/3 ⌋)，将第二多的元素和一些
其它的元素凑成 ⌊ n/3 ⌋个元素放在B中，所有其它的元素都放在C中(集合C的元素个数少于 ⌊ n/3 ⌋)，然后集合A和集合B，都去
抵消集合C，最后我们肯定能得到放在集合A中的候选元素，集合B抵消到最后剩下的一定不是我们需要的，因此在算法
的最后我们需要进行一下验证

*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

    	int n = nums.size();
    	vector<int> ret;
    	if(n == 0)
    		return ret;
    	int x = -1;
    	int cnt1 = 0;
    	int y = -1;
    	int cnt2 = 0;
    	for(int i = 0;i < n;i++)
    	{
    		if((cnt1==0 || nums[i]==x) && (cnt2==0 || nums[i]!=y))
    		{
    			x = nums[i];
    			cnt1++;
    		}
    		else if((cnt2==0 || nums[i]==y) && (cnt1==0 || nums[i]!=x))
    		{
    			y = nums[i];
    			cnt2++;
    		}
    		else
    		{
    			cnt1--;
    			cnt2--;
    		}
    	}
    	if(cnt1)
    	{
    		int cnt = 0;
    		for(int i = 0;i < n;i++)
    		{
    			if(nums[i] == x)
    				cnt++;
    		}
    		if(cnt > n/3)
    			ret.push_back(x);
    	}
    	if(cnt2)
    	{
    		int cnt = 0;
    		for(int i = 0;i < n;i++)
    		{
    			if(nums[i] == y)
    				cnt++;
    		}
    		if(cnt > n/3)
    			ret.push_back(y);
    	}
    	return ret;
        
    }
};