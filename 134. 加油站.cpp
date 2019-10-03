题目描述:

There are N gas stations along a circular route, 
where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank(汽车之油箱) 
and it costs cost[i] of gas to travel 
from station i to its next station (i+1). 
You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station s index 
if you can travel around the circuit once, otherwise return -1.

Note: 
The solution is guaranteed to be unique.

/*
假设开始设置起点start = 0, 
并从这里出发，如果当前的gas值大于cost值，
就可以继续前进，此时到下一个站点，剩余的gas
加上当前的gas再减去cost，
看是否大于0，若大于0，则继续前进。
当到达某一站点时，若这个值小于0了，
则说明从起点到这个点中间的任何一个点都不能作为起点，
则把起点设为下一个点，继续遍历。
需要着重理解为啥下一点可以从i+1开始
若从i开始累加sum，当到j点时(此时是开始从j到j+1)<0，说明从i开始
到不了加油站j+1,由于可到达加油站i+1,则diff[i]>=0，
所以diff[i+1]...+diff[j]<0-diff[i]<=0,
所以i+1不能到达加油站j+1,由于i可以到达加油站i+2,
则diff[i]+diff[i+1]>=0,
所以diff[i+2]...+diff[j]<0-(diff[i]+diff[i+1])<=0,
所以i+2不能到加油站j+1，
以此类推可知[i,j]之间所有的点都不能到达加油站j+1
*/

/*
这道题最直观的思路，是逐个尝试每一个站点，从站i点出发，
看看是否能走完全程。如果不行，就接着试着从站点 i+1出发。
假设从站点i出发,到达站点k之前,依然能保证油箱里油没见底儿，
从k出发后,见底儿了。那么就说明
diff[i]+diff[i+1]+ ... +diff[k]<0，
而除掉diff[k]以外，从diff[i]开始的累加都是>=0的。
也就是说diff[i]也是>=0的，这个时候我们还有必要
从站点i+1尝试吗？仔细一想就知道：车要是从站点 i+1出发，
到达站点k后，甚至还没到站点k,油箱就见底儿了，
因为少加了站点 i 的油。。。
因此,当我们发现到达k站点邮箱见底儿后，i到k这些站点都不用作为出发点来试验了，
肯定不满足条件，只需要从k+1站点尝试即可！
因此解法时间复杂度从O(n2)降到了 O(2n)。之所以是O(2n)，
是因为将k+1站作为始发站，车得绕圈开回k，来验证k+1是否满足。
等等，真的需要这样吗？
我们模拟一下过程：
a. 最开始，站点0是始发站，假设车开出站点p后，油箱空了，
假设sum1 = diff[0] +diff[1] + ... + diff[p]，可知sum1 < 0；
b. 根据上面的论述，我们将p+1作为始发站，开出q站后，油箱又空了，
设sum2=diff[p+1]+diff[p+2]+... +diff[q],可知sum2 < 0。
c. 将q+1作为始发站，假设一直开到了未循环的最末站,油箱没见底儿，
设sum3=diff[q+1]+diff[q+2]+...+diff[size-1],可知sum3 >= 0。
要想知道车能否开回q+1站，其实就是在sum3的基础上，
依次加上 diff[0] 到 diff[q]，看看sum3在这个过程中是否会小于0。
但是我们之前已经知道diff[0]到diff[p-1]这段路，油箱能一直保持非负，
因此我们只要算算sum3+sum1是否<0，就知道能不能开到p+1站了。
如果能从p+1站开出，只要算算sum3+sum1+sum2是否<0，
就知都能不能开回q+1站了。
因为sum1, sum2都<0，因此如果sum3+sum1+sum2>=0,那么sum3+sum1必然>=0，
也就是说，只要sum3+sum1+sum2>=0，车必然能开回q+1站。
而sum3+sum1+sum2其实就是diff数组的总和Total，
遍历完所有元素已经算出来了。因此Total能否>= 0，
就是是否存在这样的站点的 充分必要条件。
这样时间复杂度进一步从O(2n)降到了O(n)。
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        if(gas.size()==0 || cost.size()==0 || gas.size()!=cost.size())
        	return -1;
    	int n = gas.size();
    	int start = 0;
    	int total = 0;
    	int sum = 0;
        for(int i = 0; i < n; ++i) 
        {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if(sum < 0) 
            {
                start = i + 1;
                sum = 0;
            }
        }
        return (total < 0) ? -1 : start;
    }
};

//从start出发,如果油量足够,可以一直向后走 end++；  
//油量不够的时候，start向后退,最终start==end的时候，
//如果有解一定是当前 start所在位置
//这种方法有点类似于双指针维护一个窗口，然后贪心地移动
class Solution {
public: 
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
	{
		int start = gas.size() - 1;//start为出发的站点下标
        int end = 0;//end为到达的站点下标
        int sum = gas[start] - cost[start];
        while(start > end)
        {
        	if(sum >= 0)
        	{
        		sum += gas[end]-cost[end];
                ++end;
            }
            else
            {
            	--start;
                sum += gas[start]-cost[start];
            }
        }
        return sum >=0 ? start : -1;         
    }
};    