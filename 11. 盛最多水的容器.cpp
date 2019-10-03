题目描述:

Given n non-negative integers a1 , a2 , ..., an , where each represents a point 
at coordinate(坐标) (i, ai ). n vertical(垂直的) lines are drawn such that the
two endpoints of line i is at (i, ai ) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container 
contains the most water.

Note: You may not slant(倾斜) the container.

//这个问题和twoSum问题的思路类似

//贪心算法：从最大的宽度开始(计算得到这个宽度时的面积)，计算下一阶段宽度(宽度减少了1)的面积时，
//我们贪心的去掉一个数(去掉当前范围两边的高度最小的那一个使得下一个宽度阶段下的面积尽可能最大
//之所以从两边去掉数缩小宽度，而不从中间去掉一个数，是因为我们这样做可以使两个指针
//不跳过最优的点，即两个指针一定会经过最优的点)
//正确性证明:
//假设(x,y)为最优解，i向右逐渐靠近x，j向左逐渐靠近y，那么i没有可能跳过x，j也没有可能跳过y； 
//1、当j==y,i<x时,那么此时必定有height[i]<height[j],如果不是这样,
//i值就比x值更优(如果height[i]>=height[j],则此时(i,j)优于(x,y),宽度更宽，高度大于等于),
//与假设矛盾,即必定是i向右移动直到i==x；
//2、当i==x,j>y时,同理

//另外，根据这个贪心操作过程，如果问题有多个解的话，我们的这个贪心进行过程不会错过任何一个解

/*
分析最优解的特点,从而得出两个指针如何移动才能靠近最优解，进而获得解题思路
                   O
                   O
            O      O    
            O      O
            O      O
            O      O
            O      O
            x      y
如图所示,假设(x,y)为最优解，则y右边的柱子的高度一定低于x,x左边的柱子低于y(显然更低于x) 
这是最优解两边柱子高度的分布规律，我们可以把握住这个规律，得出两个指针应该怎么移动          

*/
class Solution {
public:
    int maxArea(vector<int> &height) {

    	if(height.size()==0 || height.size()==1)
    		return 0;
    	int maxArea = 0;
        int l = 0;
        int r = height.size()-1;
        while(l<r)
        {   
        	int cur = (r-l)*min(height[l],height[r]);
        	if(cur > maxArea)
        		maxArea = cur; 
            if(height[l]<=height[r])//两边去除最低的，如果两边一样高，随便去除哪个都行
            	l++;
            else 
            	r--;
        }
        return maxArea;
    }
};
