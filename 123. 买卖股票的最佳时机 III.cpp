题目描述:

Say you have an array for which the ith element is the price 
of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete 
at most two transactions.

Note: 
You may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).




//结合分治的思维(其实还是动态规划的思想，枚举所有的分割情况)
//最多的两次交易处于两个区间中，因为两个交易有先后之分，一次交易完成后才能进行
//第二次交易，两次交易一定可以位于左右的两个区间中，枚举所有的左右区间分割情况，找最大值的情况

//注：这个代码leetcode C++运行超时，Java能通过
class Solution {
    public: 
    	int maxProfit(vector<int> &prices) {
        
        if(prices.size() < 2)//区间长度小于2返回0.
        	return 0;
        int maxprofit = 0;
        if(prices.size() == 2)//区间长度为2
            return max(maxprofit, prices[1] - prices[0]);
        
        //区间长度大于等于3(这样每个区间都至少有2个点)，采取分治的思想，分为两个子区间。
        //分别求解子区间内的最大利润
        for(int i = 1; i <= prices.size()-2; i++)
        {

        	int firstMax = maxProfitCore(prices, 0, i);
        	int secondMax = maxProfitCore(prices, i, prices.size()-1);
        	int curMax = firstMax+secondMax;
            maxprofit = max(maxprofit,curMax);

        }

        return maxprofit;

    }
    //在线处理求该区间的最大利润
    int maxProfitCore(vector<int> &prices, int left, int right)
    {

        int maxProfit = 0;
        int minPrice = prices[left];
        for (int i = left + 1; i <= right; i++) 
        {
        	if(prices[i]<minPrice)
        		minPrice = prices[i];
            else
            {
            	if(prices[i]-minPrice > maxProfit)
            		maxProfit = prices[i] - minPrice;
            }

        }
           
        return maxProfit;
    }
};



//动态规划
// 思路分析：由于只能买卖两次，所以我们可以将问题分成从左边寻找一个最大的收入，从右边寻找一个最大的收入，
// 然后当这两个收入不重叠，且和为最大值就是题目的解。
//其实和上面的思路一样

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        if(n < 2)//区间长度小于2返回0.
            return 0;
        int maxprofit = 0;
        if(n == 2)//区间长度为2
            return max(maxprofit, prices[1] - prices[0]);
        vector<int> dp1(n, 0);//dp1[i]表示到i天的左边最大收入
        vector<int> dp2(n, 0);//dp2[i]表示从i天起之后右边的最大收入
        int minPrice = prices[0];
        for(int i = 1; i < n; ++i) 
        {
            dp1[i] = dp1[i-1];
            if(prices[i]<minPrice)
                minPrice = prices[i];
            else
            {
                if(prices[i]-minPrice > dp1[i-1])
                    dp1[i] = prices[i] - minPrice;
            }
        }
        int maxPrice = prices[n - 1];
        for(int i = n - 2; i >= 0; --i)
        {
            dp2[i] = dp2[i+1];
            if(prices[i]>maxPrice)
                maxPrice = prices[i];
            else
            {
                if(maxPrice-prices[i] > dp2[i+1])
                    dp2[i] = maxPrice-prices[i];
            }
        }
        for(int i = 1; i <= n-2; i++)
        {

            int firstMax = dp1[i];
            int secondMax = dp2[i];
            int curMax = firstMax+secondMax;
            maxprofit = max(maxprofit,curMax);

        }
        return maxprofit;
    }
};

