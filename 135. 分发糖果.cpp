题目描述:
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
你需要按照以下要求，帮助老师给这些孩子分发糖果：
每个孩子至少分配到1个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:
输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
示例 2:

输入: [1,2,2]
输出: 4
解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。


/*
dp思路:
start记录开始降序的位置
start记录前面的子数组中从后面起最近的一个升序(包括相等关系)的最后一个元素下标位置
即前面的子数组中从后面起最近的一个降序的第一个元素的下标位置
ratings[start-1]<=ratings[start]>ratings[start+1]>ratings[start+2]>rartings[start+3]....
当对元素进行流式处理时，如果当前位置ratings[i-1]>[i]时我们需要修正前面子数组的处理结果
修正操作到位置start处为止，因为ratings[start-1]<=ratings[start]，原来的放置满足，现在
start处的放置修正后可能更大了，当然更满足了

start只与ratings数组中存储的元素之间的相对序关系有关              
每次遇到降序从后往前更新到start为止

动态规划,流式处理,遇到一个新元素时如何根据前面的子问题的答案组合成当前子数组的
答案，即递推公式，不过这里的递推公式不是一个显示的数学表达式(因为要求的答案不是
一个数值，而是一个数组(好几个数))，这就有可能涉及到修改问题了，本题针对
当前位置i的序关系，进行相应的处理修改就能得到当前问题的答案数组

*/

class Solution {
public:
    int candy(vector<int> &ratings) {

      int size = ratings.size();
      if(size == 0)
        return 0;
        vector<int> dp(size,0);
        int start=0;
        dp[0]=1;
        for(int i = 1;i < size;i++)
        {
          if(ratings[i] > ratings[i-1])
          {
              dp[i] = dp[i-1]+1;
              start = i;
          }
          else if(ratings[i] == ratings[i-1])
          {
            dp[i] = 1;
            start = i;
          }
          else
          {
            dp[i] = 1;
            for(int j = i-1;j >= start;j--)
            {
              if(dp[j] <= dp[j+1])
                dp[j] = dp[j+1]+1;
            }

          }
      }

      int sum = 0;
      for(auto elem:dp)
        sum+=elem;
      return sum;
       
    }
   
};