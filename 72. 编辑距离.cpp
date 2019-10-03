题目描述:

给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
示例 1:

输入: word1 = "horse", word2 = "ros"
输出: 3
解释: 
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2:

输入: word1 = "intention", word2 = "execution"
输出: 5
解释: 
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
/*
根据以往的经验，对于字符串相关的题目十有八九都是用动态规划Dynamic Programming来解，
这道题也不例外。这道题我们需要维护一个二维的数组dp，
其中dp[i][j]表示从word1的前i个字符转换到word2的前j个字符所需要的步骤。
跟以往的DP题目类似，难点还是在于找出递推式
我们通过观察可以发现，当word1[i-1] == word2[j-1]时(就近原则，就地取材)，dp[i][j] = dp[i - 1][j - 1]，
其他情况时，dp[i][j]是其左，左上，上的三个值中的最小值加1，那么可以得到递推式为：

dp[i][j] =      /    dp[i - 1][j - 1]                           if word1[i - 1] == word2[j - 1]
                                替换               删除          插入
                \    min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1       else

通过递推公式我们发现还可以继续优化，用一个一维数组保存中间的结果信息，
维持一个临时变量temp保存上一行左上的值dp[i-1][j-1],对于一行的更新我们从左向右进行
*/
class Solution {
public:
    int minDistance(string word1, string word2) {

    	int m = word1.size();
        int n = word2.size();
        vector<vector<int> >dp(m+1,vector<int>(n+1));
        for(int i = 0;i <= m ;i++)
        {
            for(int j = 0; j <= n ;j++)
            {
                if(i ==0)
                    dp[i][j] = j;
                else if(j ==0)
                    dp[i][j] = i;
                else
                    dp[i][j] = min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+(word1[i-1]==word2[j-1]?0:1)));
            
            }
        }

        return dp[m][n];  
        
    }
};
//递归算法：
//流式处理，当前为从左开始
int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
         
        int m = word1.size();
        int n = word2.size();
         
        if(word1 == "")
        {
            return n;
        }
         
        if(word2 == "")
        {
            return m;
        }
        //两个参数的递归函数终止条件设计问题
        if(word1[0] == word2[0])
        {
            return minDistance(word1.substr(1), word2.substr(1));
        }
        else
        {                       //插入                                        //删除                                   //替换
            return min(1 + minDistance(word1, word2.substr(1)), min(1 + minDistance(word1.substr(1), word2), 1 + minDistance(word1.substr(1), word2.substr(1))));
        }
 
    }
//Leetcode上好多动态规划的题 ， 一般碰到这样的题
//先用递归把做出来，结果显然，TLE。既然能用递归，
//就肯定可以用动态规划，然后就把递归变成动态规划，变成动态规划后看能不能再优化空间，
//如果不能，就直接return了，如果能就优化，这个现在已经成为套路了

int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
         
        int m = word1.size();
        int n = word2.size();
         
        if(word1 == "")
        {
            return n;
        }
         
        if(word2 == "")
        {
            return m;
        }
         
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
         
        for(int i = 0; i < m + 1; ++i)
        {
            dp[i][n] = m - i;
        }
         
        for(int j = 0; j < n + 1; ++j)
        {
            dp[m][j] = n - j;
        }
         
         
        for(int i = m - 1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                if(word1[i] == word2[j])
                {
                    dp[i][j] = dp[i+1][j+1];//什么也不做
                }
                else
                {                      //插入              //删除           //替换
                    dp[i][j] = min(1 + dp[i][j+1], min(1 + dp[i+1][j], 1 + dp[i+1][j+1]));
                }
            }
        }
         
        return dp[0][0];
    }