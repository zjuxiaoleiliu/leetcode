题目描述:

Given a collection of integers that might contain duplicates, S, 
return all possible subsets.

Note:
                                //非下降顺序
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example,
If S =[1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
//解法：思考一种如何产生集合子集的方法，遍历每一个子集的产生过程
//并保证不产生重复，跳过可能产生重复的情况
//这里的方法是将一个子集看成
//由一个前缀+一个元素构成，如果加一个元素的话，
//只加唯一的一个样本，和它相等的元素都跳过去
//不是深度优先搜索，这里用的是宽度优先搜索的思想
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {

    	vector<vector<int>> ret;
    	vector<int> temp;
    	ret.push_back(temp);
    	sort(S.begin(),S.end());
    	subsetsWithDupCore(S,0,ret,temp);
    	return ret;      
    }

    void subsetsWithDupCore(vector<int> &S,int start,vector<vector<int>> &ret,vector<int> &temp)
    {   

        if(start > S.size())
            return;
        //树的层序遍历的思想，从一个起点开始，产生能产生的所有合法的子集，再从这些每一个子集递归产生它
    	for(int i = start;i<S.size();i++)//作为前缀能产生的所有子集
    	{
    		if(i!=start && S[i] == S[i-1])
    			continue;
    		temp.push_back(S[i]);//每次递推时传入的起始前缀不同
    		ret.push_back(temp);//每个子集都是在前一个合法的子集的基础上加一个元素产生的
    		subsetsWithDupCore(S,i+1,ret,temp);//遍历每一个合法子集作为前缀能产生的所有的子集
    		temp.pop_back();   //每一个合法子集作为前缀产生再加一个元素所能产生的所有合法子集时
    		                   //都是从它右边开始查找，因为题目要求按升序，主要是因为一个位置的
    		                   //元素用掉一个就抵消掉了，要产生新的子集，必须加入新的元素，必须从
    		                   //还没有用过的元素中查找

    	}
    }
};


 