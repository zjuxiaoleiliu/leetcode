题目描述:

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesnt matter what you leave beyond the new length.

//方法1:删除的元素真的是没用了，函数完成后我们无法得知元素数组的元素构成情况
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        if(n == 0)
            return 0;
        int length =-1;//尾指针的利用
        for(int i = 0;i < n;i++)
        {
            if(nums[i] != val)//流式处理，进入循环后先判断，根据判断结果决定要进行的操作
            
                nums[++length] = nums[i];   
        }
        return length+1;        
    }
};

方法2：即使函数完成了删除操作，我们仍能得知原来数组的元素情况(根据原来数组占用的内存空间位置)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       
        int n = nums.size();
        if(n == 0)
            return 0;        
        int i =0;
        int right = n;
        while(i < right)
        {
            if(nums[i] != val)
                i++;
            else
                swap(nums[i],nums[--right]);
        }
        return i;
    }
};
