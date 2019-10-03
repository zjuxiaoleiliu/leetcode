给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

    	int n = nums.size();
    	if(n == 0) 
    		return 0;
    	//这里用了两个数组保存中间的信息
        vector<int> len(n,1);//以nums[i]结尾的最长子序列的长度
        vector<int> cnt(n,1);//以nums[i]结尾的最长子序列的个数
        int maxLen = 0;
        for(int i = 0; i < n; i++)//流式处理 
        {
            for(int j = 0; j < i; j++) 
            {
                if(nums[i] > nums[j]) 
                {
                    if(len[j] + 1 > len[i]) 
                    { //如果+1长于当前LIS 则找到了更长的
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    } 
                    else if(len[j] + 1 == len[i]) 
                    //如果+1等于当前LIS 则说明找到了新组合
                    	cnt[i] += cnt[j];                    
                }
            }
            maxLen = max(maxLen, len[i]);
        }
        int ret = 0;//最长子序列的总个数=sum(以元素nums[i]结尾能达到此最长子序列个数和)
        for(int i = 0; i < n; i++)
        	if(len[i] == maxLen)
        		ret += cnt[i];
        return ret;        
    }
};