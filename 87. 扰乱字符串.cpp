题目描述:

Given a string s1, we may represent it as a
               //分割 
binary tree by partitioning it to two non-empty 
substrings recursively.

Below is one possible representation of s1 ="great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
//爬行字符串   
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node"gr"and swap its two children,
 it produces a scrambled string"rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that"rgeat"is a scrambled string of"great".

Similarly, if we continue to swap the children of nodes"eat"and"at",
 it produces a scrambled string"rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that"rgtae"is a scrambled string of"great".

Given two strings s1 and s2 of the same length, 
determine if s2 is a scrambled string of s1.

//方法1：基于传统的递归方法，遍历S1每一种初始分割方式，一个个的递归判断(类似于树的镜像的判断方法)
//遇到成功的分割时要及时终止函数(只要有一种情况成功了就行了)
//简单的说，就是s1和s2是scramble的话，那么必然存在(只要成功就行了)一种分割，将s1分成s11和s12两段，
//有s21和s22.那么要么s11和s21是scramble的并且s12和s22是scramble的；
//s11和s22是scramble的并且s12和s21是scramble的。
class Solution {
public:
    bool isScramble(string s1, string s2)
     {
        if(s1 == s2)
          return true;
        //另外在进入递归前需要剪枝，判断两个字符串是否包含相同的字母,减少不必要的操作
        int c[26] = {0};
        for(int i = 0;i < s1.length();i++)
        {
          c[s1[i]-'a']++;
          c[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++)
          if(c[i] != 0)
            return false;
        //只有两个以上的长度时才有继续递推下去的必要
        for(int i = 1;i < s1.length();i++)//遍历s1的每一种根节点的划分方式，枚举划分左半部分的节点个数
        {  
          //此种根节点划分情况下，根节点处的两个孩子结点没有交换
          if(isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
            return true;
          //此种根节点划分情况下，根节点处的两个孩子结点发生了交换
          if(isScramble(s1.substr(0,i), s2.substr(s2.length()-i)) && isScramble(s1.substr(i), s2.substr(0,s2.length()-i)))
            return true;       
        }
        return false;       
    }

};


/*解法2：动态规划方法
根据以往的经验来说，与符串有关的题十有八九可以用DP来做，那么难点就在于如何找出递推公式。
这其实是一道三维动态规划的题目，我们提出维护量res[i][j][n]，
其中i是s1的起始字符下标，j是s2的起始字符下标，而n是当前的字符串长度,(其实还是把上面的递归函数翻译成动态规划，根据
递归函数的参数接口，设计动态规划使用的保存中间信息的数据结构)
res[i][j][len]表示的是以i和j分别为s1和s2起点的长度为len的字符串是不是互为scramble。
有了维护量,我们来看看递推式，也就是怎么根据历史信息来得到res[i][j][len]。
判断这个是不是满足scramble string，其实我们首先是把当前s1[i...i+len-1]字符串劈一刀分成两部分，
然后分两种情况：第一种是s1[i...i+len-1]左边和s2[j...j+len-1]左边部分是不是scramble，
以及右边和s2[j...j+len-1]右边部分是不是scramble；
第二种情况是s1[i...i+len-1]左边和s2[j...j+len-1]右边部分是不是scramble，
以及右边和s2[j...j+len-1]左边部分是不是scramble。如果以上两种情况有一种成立，
说明s1[i...i+len-1]和s2[j...j+len-1]是scramble的。
而对于判断这些左右部分是不是scramble我们是有历史信息的，
因为长度小于n的所有情况我们都在前面求解过了（也就是长度是最外层循环，其实也就是数组可以设计成dp[len][i][j])。
上面说的是劈一刀的情况，对于s1[i...i+len-1]我们有len-1种劈法，在这些劈法中只要有一种成立，
那么两个串就是scramble的。总结起来递推式是:


res[i][j][len] = || (res[i][j][k] && res[i+k][j+k][len-k] || res[i][j+len-k][k]&&res[i+k][j][len-k]) 对于所有1<=k<len，
也就是对于所有len-1种劈法的结果求或运算。因为信息都是计算过的，对于每种劈法只需要常量操作即可完成，
因此求解递推式是需要O(len)（因为len-1种劈法）。
如此总时间复杂度因为是三维动态规划，需要三层循环，加上每一步需要线行时间求解递推式，
所以是O(n^4)。虽然已经比较高了，但是至少不是指数量级的，动态规划还是有很大优势的，空间复杂度是O(n^3)。


这里的动态规划主要是第一步根节点的分割，第一步根节点的分割状态确定后,后面要进行的子问题的状态转移也就确定了
由于本问题要求的是一种可能性成功即可，所以这里的递推关系是枚举第一步根节点分割的所有状态情况后的子问题状态走向，
然后对枚举的情况做 || 即可
*/
class Solution {
public:
    bool isScramble(string s1, string s2) 
    {

      if(s1.size() != s2.size()) 
        return false;
      if (s1 == s2)
        return true;

      int n = s1.size();
      vector<vector<vector<bool> > > dp(n+1, vector<vector<bool> >(n, vector<bool>(n,false)));
      for(int i = 0; i < n; ++i) 
      {
        for(int j = 0; j < n; ++j)  
          dp[1][i][j] = s1[i] == s2[j];  
      }
      for(int len = 2; len <= n; ++len) 
      {
        for(int i = 0; i <= n-len; ++i)
        {
          for(int j = 0; j <= n-len; ++j) 
          {

            for(int k = 1; k < len; ++k)//注意这里的递归公式中i,j求解的顺序没有要求，但是len的顺序必须从小到大
              if((dp[k][i][j] && dp[len - k][i+k][j+k]) || (dp[k][i][j+len-k] && dp[len-k][i+k][j])) 
                {
                  dp[len][i][j] = true;
                  break;
                }
              
          }

        }

      }

      return dp[n][0][0]; 

    }
};

