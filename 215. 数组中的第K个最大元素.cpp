在未排序的数组中找到第 k 个最大的元素。请注意，
你需要找的是数组排序后的第 k 个最大的元素，
而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

//万能的最小堆思路
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

    	int n = nums.size();
    	if(k < 1 || n < k)
    		return INT_MIN;
    	priority_queue<int,vector<int>,greater<int>> q;//最小堆
    	for(int i = 0;i < n;i++)
    	{
    		if(i < k)
    			q.push(nums[i]);
    		else
    		{
    			int temp = q.top();
    			if(nums[i] > temp)
    			{
    				q.pop();
    				q.push(nums[i]);
    			}
    		}
    	}
    	return q.top();        
    }
};


//利用快排的思想
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

    	int n = nums.size();
    	if(k < 1 || n < k)
    		return INT_MIN;
    	int start = 0;
	    int end = n - 1;
	    int index = partition(nums,start, end);
		//循环前循环用到的变量进行的变量初始值操作
	    while(index != k-1)
	    {
	        if(index > k-1)
	        {
	            end = index-1;
	            index = partition(nums,start, end);
	        }
	        else
	        {
	            start = index + 1;
	            index = partition(nums,start, end);
	        }
	    }
	    return nums[k-1];
    	     
    }

    int partition(vector<int>& nums,int start,int end)
	{	    
	    int index = rand()%(end-start+1)+start;
	    swap(nums[index], nums[end]);
	    int small = start - 1;//尾指针的思想
	    for(int i = start; i < end; ++i)
	    {
	        if(nums[i] > nums[end])
	        {
	            ++ small;
	            if(small != i)
	                swap(nums[i], nums[small]);
	        }
	    }
	    ++ small;
	    swap(nums[small], nums[end]);
	    return small;
	}
};


int partition1(vector<int>& nums,int start,int end)
	{	    
	    int index = rand()%(end-start+1)+start;
	    swap(nums[index], nums[end]);
	    int small = start - 1;//尾指针的思想
	    for(int i = start; i < end; ++i)
	    {
	        if(nums[i] < nums[end])
	        {
	            ++ small;
	            if(small != i)
	                swap(nums[i], nums[small]);
	        }
	    }
	    ++ small;
	    swap(nums[small], nums[end]);
	    return small;
	}


int partition2(vector<int>& nums,int start,int end)
	{	    
	    int index = rand()%(end-start+1)+start;
	    swap(nums[index], nums[end]);
	    int i = start;
	    int j = end-1;
	    while(i<=j)
	    {
	    	while(i<=j && nums[i]<nums[end])i++;
	    	if(i>j)
	    		break;
	    	while(j>=i && nums[j]>nums[end])j--;
	    	if(i < j)
	    	{
	    		swap(nums[i],nums[j]);
	    		i++;
	    		j--;
	    	}
	    	else
	    		break;
	     
	    }
	    swap(nums[i], nums[end]);
	    return i;
	}
void quicksort(int data[],int start,int end)
{
	if(start == end)
		return;
	int index = partition(data,start,end);
	if(index > start)
		quicksort(data,start,index-1);
	if(index < end)
		quicksort(data,index+1,end);

}


