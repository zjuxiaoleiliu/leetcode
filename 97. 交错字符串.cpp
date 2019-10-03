题目描述:
                                                
给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

示例 1:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true
示例 2:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false


/*

设dp[i][j]表示s3的前i+j个字符可以由s1的前i个字符和s2的前j个字符交织而成。
就近原则
状态转移方程：有两种情况

第一个状态转移方程：
dp[i][j]= {(dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)}
dp[i-1][j]表示若s3的前i+j-1个字符能够由s1前i-1个字符和s2的前j个字符交织而成，
那么只需要s1的第i个字符与s3的第i+j个字符相等（charAt索引从0开始），那么dp[i][j]=true;
第二个状态转移方程：
dp[i][j]= {(dp[i][j-1] && s2.charAt(j - 1) == s3.charAt(i + j - 1)}
dp[i-1][j]表示若s3的前i+j-1个字符能够由s1前i个字符和s2的前j-1个字符交织而成，
那么只需要s2的第j个字符与s3的第i+j个字符相等（charAt索引从0开始），那么dp[i][j]=true;

这种字符串类型的动态规划和以前遇到的动态规划类似，
只不过每一个位置的处理情况(s3每一个位置的处理情况分为两种：用s1,或者用s2)有好几种，

其实这个问题我们还可以从第一个位置开始处理后决定后面的子问题，这样似乎显得的更自然一些
第一个位置可以用s1的第一个字符，如果s1[1] == s3[1] ,然后判断子问题s1[2:size1],s2[1:size2],s3[2:size3]
如果s2[1] == s3[1]，然后判断子问题s1[1:size1],s2[2:size2],s3[2:size3]
不过这样解决问题，书写上不如从最后处理流畅

动态规划  流式处理  如何分解整个问题为子问题：一步的状态定过后，其子问题的分解状态去向就确定了

动态规划：更新一个值(最大最小) 获得当前阶段阶段的值(一个数值，裴波那切数列，多个值，一个数值数组，格雷码)
得到当前阶段的计数值：相加，得到当前阶段时的状态情况：枚举当前位置的不同处理，转向不同子问题状态，然后
对所有的情况做并(||)  
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

    	int size1 = s1.size();
        int size2 = s2.size();
        int size3 = s3.size();
        if(size1+size2 != size3)
            return false;
        vector<vector<bool> > dp(size1+1, vector<bool>(size2+1, false));
        for(int i = 0; i <= size1; i ++)
        {
            for(int j = 0; j <= size2; j ++)
            {
                if(i == 0 && j == 0)
                // start
                    dp[i][j] = true;
                else if(i == 0)
                    dp[i][j] = dp[i][j-1] && (s2[j-1]==s3[j-1]);
                else if(j == 0)
                    dp[i][j] = dp[i-1][j] && (s1[i-1]==s3[i-1]);
                else
                    dp[i][j] = (dp[i][j-1] && (s2[j-1]==s3[i+j-1])) || (dp[i-1][j] && (s1[i-1]==s3[i+j-1]));
            }
        }
        return dp[size1][size2];     
    }
};