题目描述:

Implementint sqrt(int x).

Compute and return the square root of x.

class Solution {
public:
    int mySqrt(int x) {

    	if(x < 0)
    		return -1;
    	if(x == 0)
    		return 0;
    	int begin = 1;
    	int end = x;
    	while(begin <= end)
    	{ //不用mid = (begin+end)/2是为了防止发生溢出
    		int  mid = begin+(end-begin)/2;
    		if(x/mid > mid)//由于是整数，所以x/mid>=mid+1,进而x=(x/mid)*mid+r>=(mid+1)*mid+r>mid*mid
    			begin= mid+1;
    		else if(x/mid < mid)//由于是整数，所以由x/mid < mid可以得出x/mid<=mid-1,进而x=(x/mid)*mid+r
    			end = mid-1;//<=(mid-1)*mid+r<(mid-1)*mid+mid=mid*mid  
    		else
            return mid;//平方根返回int类型，我们这里返回的是向下取整的结果
    	}
    	return end;//如果循环正常的结束的话，最后的情况是begin>end
                   //它的上一个搜索的范围为只有一个数begin==end的情况
    }              //我们需要返回向下取整的情况，故返回end
};





class Solution {
public:
    int mySqrt(int x) 
    {
        if(x < 0)
            return -1;
        if(x == 0)
            return 0;
        long left = 1;
        long right = x;
        while(left <= right)
        {
            long mid=left+(right-left)/2;
            if(mid*mid==x)
                return mid;
            if(mid*mid<x)
                left=mid+1;
            else
                right=mid-1;
        }
        return right;
    }
};