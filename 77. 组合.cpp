题目描述:

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
//没有剪枝的暴力dfs
//以1-n这n个位置的情况进行遍历，一个位置有两种处理方式：选取、放弃
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {

    	vector<vector<int>> ret;
    	vector<int> temp;
    	combineCore(n,1,ret,temp,k);
    	return ret;       
    }

    void combineCore(int n,int index,vector<vector<int>> &ret,vector<int> &temp,int k)
    {
    	if(index == n+1)//对n个位置的一趟处理进行完了，看一看是否这一趟处理选取出来了k个数
    	{
    		if(temp.size() == k){
    			ret.push_back(temp);
    		}

    		return;
    	}    
    	temp.push_back(index);
    	combineCore(n,index+1,ret,temp,k);
    	temp.pop_back();
    	combineCore(n,index+1,ret,temp,k);
    
    }
};

//dfs+剪枝，这里的思路是遍历k个数的组合的每一个位置可以取的所有的值的情况
class Solution{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ret;
        vector<int> temp;
        dfs(1, k, n, temp, ret);
        return ret;
    }

private:
    void dfs(int index, int k, int n,vector<int> &temp,vector<vector<int>> &ret)
    {
        if(temp.size() == k)
        {
            ret.push_back(temp);
            return;
        }
        for(int j = index; j <= n; j++)
        {
            if(k - temp.size() > n - j + 1)
                break;
            temp.push_back(j);
            dfs(j+1, k, n, temp, ret);
            temp.pop_back();
        }
    }
};

