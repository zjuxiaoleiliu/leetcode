题目描述:

给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。
示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

/*
pa+pb = k
当A[pa-1] < B[pb-1]时，我们反证证明A[pa-1]这个值在将数组A和B合并后
的数组中排在第k个位置之前，如果不是这样子，
那么A[pa-1]这个值将至少可以排在第k个位置及之后的位置
所以A[pa-1]这个值前面应该应该还得至少有k-1个元素，
在数组A中，A[pa-1]这个值前有pa-1个元素
由于A[pa-1] < B[pb-1],所以数组B中至多有pb-1个元素值
可以排在A[pa-1]这个值之前。
也即，我们可以得出结论：A[pa-1]这个值之前至多
可以有pa-1+pb-1=k-2个元素，这与
A[pa-1]这个值之前至少有k-1个元素相矛盾。
所以我们可以去掉数组A中的[0,pa-1]这个范围中
的数，它们不可能是第k个数
*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
    	int total = m + n;
		if(total%2==1)
			return findKth(A, m, B, n, total/2 + 1);
		else
			return (findKth(A, m, B, n, total/2)+findKth(A, m, B, n, total/2 + 1))/2;
    }
    double findKth(int a[], int m, int b[], int n, int k)
    {   
                            //m<=n
        //always assume that m is equal or smaller than n
    	if(m > n)
    		return findKth(b, n, a, m, k);
    	if(m == 0)
    		return b[k - 1];
	    if(k == 1)
	    	return min(a[0], b[0]);
	    //下面的k大于等于2
	    //divide k into two parts
	    int pa = min(k / 2, m), pb = k - pa;
	    if(a[pa - 1] < b[pb - 1])
	    	return findKth(a + pa, m - pa, b, n, k - pa);
	    else if(a[pa - 1] > b[pb - 1])
	    	return findKth(a, m, b + pb, n - pb, k - pb);
	    else
	    	return a[pa - 1];
    }

};

