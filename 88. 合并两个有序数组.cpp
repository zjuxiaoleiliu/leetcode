题目描述:

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note: 
You may assume that A has enough space to hold additional elements from B.
The number of elements initialized in A and B are m and n respectively.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if(n == 0)
            return;

        int indexA = m-1;
        int indexB = n-1;
        int index = m+n-1;

        while(indexA >=0 && indexB >= 0)
        {
            if(nums2[indexB] > nums1[indexA])
                nums1[index--] = nums2[indexB--];
            else
                nums1[index--] = nums1[indexA--];
        }

        while(indexB>=0)//如果是nums1还有元素的话，因为nums1的元素就在本地，所以不用自己移动自己
            nums1[index--] = nums2[indexB--];      
    }
};
