题目描述:

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A =[1,1,1,2,2,3],

Your function should return length =5, and A is now[1,1,2,2,3].

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 1)
            return 0;
        int last = 0;
        int cnt = 1;
        for(int i = 1;i < n;i++)
        {
            if(nums[i] == nums[last])
            {
                if(cnt == 1)
                    {
                        cnt++;
                        nums[++last] = nums[i];//因为涉及到移动元素
                    }//所以[last,i)之间的元素不一定是有序的,当然
            }      //根据题意，[i,n)之间的元素一定是升序的
            else
            {   
                nums[++last] = nums[i];
                cnt = 1;
            }

        }

        return last + 1;
       
    }
};