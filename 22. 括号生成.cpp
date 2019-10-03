题目描述:

给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]


//方法1：动态规划递归实现
class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ret;
        if(n<1)
            return ret;
        return generateParenthesisCore(n);       
    }

    vector<string> generateParenthesisCore(int n)
    {
        if(n == 0)
            return {""};
        if(n == 1)
            return {"()"};
        vector<string> ret;
        for(int i = 0;i<n;i++)
        {   
            vector<string> in = generateParenthesisCore(i);
            vector<string> out = generateParenthesisCore(n-1-i);
            for(auto elem1:in)           
                for(auto elem2:out)                
                    ret.push_back("("+elem1+")"+elem2);
        }
        return ret;
    }
};


//方法2：动态规划问题，直接计算出来
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n<1)
        	return ret;
    	unordered_map<int,vector<string>>dp;
    	dp[0]={""};
    	dp[1]={"()"};
    	for(int i = 2;i<=n;i++)
    	{
    		vector<string> temp;
    		for(int j = 0;j<i;j++)
    		{
    			for(auto elem1:dp[j])
    			{
    				for(auto elem2:dp[i-1-j])
    				{
    					temp.push_back("("+elem1+")"+elem2);
    				}
    			}
    		}
        
    		dp[i] = temp;
    	}

    	return dp[n];
        
    }
};

//方法3：递归回溯+剪枝
//右括号只能用它前面的左括号抵消(所以此位置放置右括号时必须确保此位置之前的左括号数大于右括号数)
//此问题每个位置放置的元素有两种可能，不限制重复，只是要注意是否能够满足放置的条件
class Solution {
public:
    
    vector<string> generateParenthesis(int n)
    {
    	vector<string> ret;
        if(n < 1)
            return ret;
        string temp;
        generateParenthesisCore(n, n,ret,temp);
        return ret;
    }
    void generateParenthesisCore(int l, int r,vector<string> &ret,string &temp)
    {
        if(l == 0 && r == 0)//说明左括号和右括号都用完了，即到达末尾了
        	ret.push_back(temp);
        else
        {   //说明还没有到达末尾

        	//思考当前位置可以放置的所有合法值进行递归遍历
            if(l > 0)//思考什么时候此位置可以放置左括号
            {
            	temp.push_back('(');
            	generateParenthesisCore(l - 1, r,ret,temp);
            	temp.pop_back();

            }

            if(r > l)//思考什么时候此位置可以放置右括号
            {//(当此位置前的左括号多于右括号时，也就是它前面有左括号能抵消这个放置的右括号)
            	temp.push_back(')');
                generateParenthesisCore(l, r - 1,ret,temp);
                temp.pop_back();

            }

        }
    }
};