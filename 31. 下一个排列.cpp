题目描述:

实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1


class Solution {
public:
    void nextPermutation(vector<int> &num) {

        if(num.size() == 0 || num.size() == 1)
            return;
        //从右边开始试探：num的[i,n-1]这个下标范围是否有下一个排列，如果有
        //的话，就可以停下来了，一个数组没有下一个排序的情况是：这个数组是
        //递减的，如果我们停下来了，说明此时刚好num[i] < num[i+1],而由我们
        //这个程序操作的流程，我们可以知道num[i+1:n-1]是递减的(这个范围不存在
        //下一个排列)，num[i:n-1]的下一个排列是从num[i+1:n-1]中找到一个最小的
        //大于num[i]的数(由于num[i+1:n-1]是递减的，即从右边起第一个大于num[i]的
        //数)，将找到的这个数和num[i]做一下交换，易知此时num[i+1:n-1]仍然是递减的
        //最后我们需要把num[i+1:n-1]排成最小的排列，即进行reverse操作    
        for(int i = num.size()-2;i>=0;i--)
        {
            if(num[i] < num[i+1])
            {
                int j = num.size()-1;
                while(j>i)
                {
                    if(num[j] > num[i])
                        break;
                    j--;
                }
                swap(num[i],num[j]);
                int begin = i+1;
                int end = num.size()-1;
                while(begin<end)
                {                       
                    swap(num[begin],num[end]);
                    begin++;
                    end--;                     
                }
                return;
            }
        }
        int begin = 0;
        int end = num.size()-1;
        while(begin<end)
        {
            swap(num[begin],num[end]);
            begin++;
            end--;
        }     
    }

};

