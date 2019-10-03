题目描述:

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction
 (ie, buy one and sell one share of the stock), design an algorithm 
 to find the maximum profit.

class Solution {
public:
    int maxProfit(vector<int> &prices) {

    	int size = prices.size();
    	if(size == 0 ||size == 1)
    		return 0;
    	int ret = 0;
    	int minPrice = prices[0];

    	for(int i = 1;i<size;i++){

    		if(prices[i] < minPrice)//流式处理，进来先不忙着处理，先判断，再根据判断结果决定要进行的操作
    			minPrice = prices[i];
    		else 
			{
				if(prices[i] - minPrice > ret)
					ret = prices[i] - minPrice;
			}
    	}

    	return ret;



        
    }
};