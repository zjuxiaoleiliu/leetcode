题目描述:
给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。

一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置
所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

示例 1:

输入: S = "rabbbit", T = "rabbit"
输出: 3
解释:

如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
(上箭头符号 ^ 表示选取的字母)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
示例 2:

输入: S = "babgbag", T = "bag"
输出: 5
解释:

如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。 
(上箭头符号 ^ 表示选取的字母)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
 
/*


给定2个字符串s, t，求t在s中出现的次数。要求可以是不连续的，但是t在s中的顺序必须和t以前的一致。
状态定义：
dp[i][j]代表S[0~i-1]中等于T[0~j-1]的不同子串的个数。
递推关系式：
S[i-1]!= T[j-1]：dp[i][j] = dp[i-1][j]（不选择S中的s[i-1]字符）
S[i-1]==T[j-1]：dp[i][j] = dp[i-1][j-1]（选择S中的s[i-1]字符）+dp[i-1][j]（不选择S中的s[i-1]字符）
初始状态：第0列：dp[i][0] = 1，第0行：dp[0][j] = 0

观察递推公式，同一行的情况下，j的计算顺序其实是没有什么关系的，因为dp[i][j]只和前一行的
dp[i-1][j-1],dp[i-1][j]有关，和本行的其他元素是没有关系的，所以用二维数组的情况下其实
只要初始的前一行有了，后面的行的更新中行中元素的更新顺序可以随意
*/

class Solution {
public:
    int numDistinct(string S, string T) {

        int m = S.size();
        int n = T.size();        
        vector<vector<unsigned> > dp(m+1, vector<unsigned>(n+1, 0));
        for(int i = 0; i <= m; i ++)
            dp[i][0] = 1;//对应把S中的字符全部删除完       
        for(int i = 1; i <= m; i ++)
        {
            for(int j = 1; j <= n; j ++)
            {  
                if(S[i-1] == T[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }        
        return dp[m][n];       
    }

};

//动态规划用一维数组，在使用中不难发现该dp二维数组可以降维，注意改变数组元素值时由后往前

class Solution {
public:
int numDistinct(string S, string T) {
    int n=T.size();
    vector<unsigned> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i < S.size()+1;i++)
    {
        for(int j=n;j>=1;j--)
        {
            if(S[i-1]==T[j-1])
                dp[j]=dp[j]+dp[j-1];
        }
    }
    return dp[n];
 }

};