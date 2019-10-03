题目描述:

Given a sorted array, remove the duplicates in place 
such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must
 do this in place with constant memory.

For example,
Given input array A =[1,1,2],

Your function should return length =2, and A is now[1,2].


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
    	if( n < 1)
    		return 0;
    	int last = 0;
    	for(int i = 1;i < n;i++){
    		if(nums[i] != nums[last])
    		{	
    			if(last+1 < i)
    				nums[last+1] = nums[i];
    			last++;
    		}
    	}

    	return last+1;        
    }
};