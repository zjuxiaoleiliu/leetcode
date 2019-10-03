题目描述:

Given an array of non-negative integers, 
you are initially positioned at the first index of the array.

Each element in the array represents 
your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A =[2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. 
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)


//最优解法：贪心算法
//其实这个思路相当于利用了广度优先遍历的思想(或者树的层次遍历的思想)
//只不过这里的实现没有使用队列，因为我们这里的元素不像树那样是
//一层一层存放的，这里是顺序存储在一个从左到右的数组中，因此
//不像树的层次遍历那样需要用一个辅助的队列数据结构，来一层层的处理
//这里用一个变量值就可以说明一层的“范围”，直接在原地数组中进行
//类似于树的层序遍历的处理方法思想
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)
            return 0;
        //变量ret含义：第几圈
        int ret = 0;//初始化时刚开始时处于第0圈，所以ret初始值为0
        int last = 0;//刚开始圈的范围
        int cur = 0;
        //注意变量的值要和状态相对应
        for(int i = 0; i < n; ++i) 
        {       //last变量的含义：上一圈元素确定的范围作为当前圈的范围
            if(i > last)//进入新的一圈
            {
                last = cur;
                ++ret;
                cur = i+nums[i];
            }
            else cur = max(cur, i+nums[i]);//当前圈的元素确定的范围作为下一圈的范围
        }

        return ret;
    }
};
  
//广度优先遍历
//leetcode java用时13ms,C++用时20ms
class Solution {
public:
    int jump(vector<int> &nums) {
        
        int n = nums.size();
        if(n == 0 || n ==1)
            return 0;
        queue<int> q;
        vector<bool> visited(n,false);
        q.push(0);
        visited[0] = true;
        int step = -1;//要特别注意这里的初始化，
        while(!q.empty()) 
        {
            step++;//变量的值的触发一定要和状态保持一致
            int size = q.size();
            while(size--) 
            {
                int i = q.front();
                q.pop();
                //为了避免超时，这里对j的遍历采用从大到小的贪心策略
                for(int j = nums[i]; j >=1; j--) 
                {
                        if(i + j < n-1 ) 
                        {
                            if(visited[i+j]==false)
                            {
                                q.push(i + j);
                                visited[i+j] = true;
                            }
                        }
                        else
                           return step+1;            
                    }                               
            }
        }
        return step;      
    }
};

       
                      

