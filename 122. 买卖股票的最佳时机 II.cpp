题目描述:

Say you have an array for which the ith element is the price 
of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions 
as you like (ie, buy one and sell one share of the stock multiple times).
However, you may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).

//思路：判断相邻是否递增，因为连续递增可以合起来看为一次买入卖出操作，
//所以统计所有递增量即可

//因为可以多次买卖，假设取得最优的利润所有经过的交易为：
//a1买入，b1卖出；a2买入，b2卖出；...ai买入，bi卖出；
//一次交易的利润等于：
//prices[b1]-prices[a1]=(prices[a1+1]-prices[a1])+(prices[a1+2]-prices[a1+1])
//+...(prices[b1]-prices[b1-1]),我们说这些小区间一定是连续递增的，因为如果不是
//这样，我们可以去掉不递增的小区间，会导致利润增大(去掉不递增的小区间，
//将这次交易划分为连续递增的多次交易)，会使得利润变得更大

class Solution {
public:
    int maxProfit(vector<int> &prices) {

    	if(prices.size()<2)
            return 0;
        int ret = 0;
        for(int i =1;i<prices.size();i++){
            if(prices[i]>prices[i-1])
                ret += prices[i]-prices[i-1];
        }

        return ret;
        
    }
};