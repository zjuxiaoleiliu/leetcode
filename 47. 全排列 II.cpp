题目描述:

给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]


class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) 
    {

    	vector<vector<int>> ret;
    	int size = num.size();
    	if(size == 0)
    		return ret;
    	permuteUniqueCore(num,0,ret);
    	return ret;           
    }

    bool check(vector<int>&num,int begin,int cur)
    {
        for(int pre=begin;pre<cur;pre++)
        {
            if(num[cur] == num[pre]) 
                return false;
        }
        return true;
    }

    void permuteUniqueCore(vector<int> &num,int index,vector<vector<int>> &ret)
    {
    	if(index == num.size())
    	{
    		ret.push_back(num);
    		return;
    	}
    	else
    	{   //每个位置可以放置的元素信息放在原数组中
            //不过现在元素有重复，不像以前是一个set没有重复
    		for(int i = index;i<num.size();i++)
    		{   //确保当前位置要放置的元素做到不重复放置
    			if(i == index)
                    permuteUniqueCore(num,index+1,ret);
                     //前缀扩展解释法
    			else if(check(num,index,i))//排除重复的情况,要确保处理完当前位置后，剩下要排列的子数组是唯一的
    			{                                        //这里的唯一对子数组中元素出现的顺序没有要求，因为只要
    				swap(num[index],num[i]);             //两个子数组中的元素一样，虽然元素的相对次序不一样，但是                  
    			    permuteUniqueCore(num,index+1,ret);  //对这两个子数组全排列后得到的不重复的全排列是一样的
    			    swap(num[index],num[i]);
    		    }    		   		 
    		}
    	}
    }
};