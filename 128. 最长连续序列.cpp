题目描述:

给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。



class Solution {
public:
    int longestConsecutive(vector<int> &num) {

    	unordered_set<int> mySet(num.begin(),num.end());
        int ret = 0;
        for(auto val:num)
        {
        	if(mySet.find(val) == mySet.end())//说明包含val的最长连续子序列已经获得过了，不用重新寻找
        		continue;
        	mySet.erase(val);//在集合mySet中的元素，说明包含它们的最长连续子序列还没有确定

        	int left = val;
        	int right = val;//初始化范围的左右边界

        	while(mySet.find(left-1) !=mySet.end())
        	{
        		mySet.erase(left-1);
        		left = left-1;
        	}
            while(mySet.find(right+1) !=mySet.end())
        	{
        		mySet.erase(right+1);
        		right = right+1;
        	}
            
            if((right-left+1)>ret)
            	ret = right-left+1;
        }

        return ret;

        
    }
};