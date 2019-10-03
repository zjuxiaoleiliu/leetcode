题目描述:

Given an array of integers, every element appears three times except for one. 
Find that single one.

Note: 
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


class Solution {
public:
    int singleNumber(int A[], int n) {

    	int result = 0;
    	for(int i =0;i < sizeof(int)*8;i++)//分别求出结果各个位的值
    	{                                  //故先来一个循环遍历结果的每一位

    		int mask = 1<<i;
    		int bitCnt = 0;
    		for(int j = 0;j < n;j++)
    		{
    			if((A[j] & mask)!=0)
    				bitCnt++;

    		}

    		result|= (bitCnt%3)<<i;

    	}

    	return result;
        
    }
};