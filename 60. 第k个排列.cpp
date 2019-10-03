题目描述:

The set[1,2,3,…,n]contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"

Note:
Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"


/*
方法1：全排列暴力解法
这里是在原地保存每一个位置能放置的元素的信息
*/

class Solution {
public:
    string getPermutation(int n, int k) {

        string ret;
        string s;
        for(int i= 1;i <= n;i++)
            s.push_back('0'+i);
        getPermutationCore(s,0,ret,k);
        return ret;       
    }
                //注意这里的参数s的类型只能是传值参数，而不能是引用参数
    bool getPermutationCore(string s,int index,string &ret,int &k)
    {   
        if(index == s.size())
        {
            k--;
            if(k == 0)
            {
                ret = s;
                return true;
            }             
        }
        sort(s.begin()+index,s.end());//参数s的类型为传值参数主要是因为这里
        for(int i = index;i < s.size();i++)//的排序操作
        {   
            swap(s[index],s[i]);
            if(getPermutationCore(s,index+1,ret,k);)
                return true;
            swap(s[index],s[i]);
        }
        return false;
    }
};

/*
还是全排列爆搜,但是没有用到排序
这里是单独使用了一个额外的数据结构保存每一个位置能够放置的元素的信息，
没有在原地保存这个信息
*/
class Solution {
public:
    string getPermutation(int n, int k) {

        string ret(n,'0');
        vector<bool> visited(n,false);
        dfs(visited,0,ret,k);
        return ret;       
    }

    bool dfs(vector<bool> &visited,int index,string &ret,int &k)
    {   
        if(index == visited.size())
        {
            k--;
            if(k == 0)
                return true;            
        }
        //枚举index这个位置可以放置的所有可能的元素(按照从小到大的顺序)
        for(int i = 0;i < visited.size();i++)
        {   
            if(visited[i] == false)
            {
                visited[i] = true;
                ret[index] = ('0'+i+1);
                if(dfs(visited,index+1,ret,k))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
};

/*
康托展开(Cantor expansion)是一个全排列到一个自然数的双射, 康托展开的实质是
计算当前排列在所有由小到大全排列中在它前面的排序有多少个，因此是可逆的。
康托展开运算：
X = a_n*(n-1)!+a_(n-1)*(n-2)!+....+a1*0!
其中，a_i为整数，并且0<=a_i<i,1<=i<=n
a_i表示原数的第i位在当前未出现的元素中排在它前面的数有几个，也即排在
第几个(以0为起始下标),如果以1为起始下标，则原数的第i位元素是当前未出现的
元素中的第(a_i + 1)个元素，根据a_i的含义a_1天然的等于0
这个计算出来的康托展开值X的含义是排在当前这个排列之前的排列有多少个,即如果以0为
坐标起点，当前的这个排列的下标值

z康托展开的逆运算
既然康托展开是一个双射(对应关系是唯一的)，那么一定可以通过康托展开值求出原排列，即可以求出n的
全排列中第x大排列。
*/



//逆康托尔运算的一种实现
class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> numFactorial(n+1,1);
        for(int i = 1;i<=n;i++)
            numFactorial[i] = i*numFactorial[i-1];
        vector<bool> visited(n + 1, false);
        string ret = "";
        k -= 1;//需要减去自身,得到的才是这个排列所对应的康托尔展开值
        for(int i = n - 1; i >= 0; --i)
        {//从高位到低位进行寻找
            int index = k / numFactorial[i];
            k = k % numFactorial[i];
            int cnt = 0;
            //在还未使用的数中，找第index+1大的数(从1开始)
            for(int j = 1; j <= n; ++j)
            {
                if(visited[j] == false)//流式处理判断
                {
                    ++cnt;
                    if(cnt == index+1)
                    {
                        ret +=to_string(j);
                        visited[j] = true;
                        break;
                    }
                }               
            }
        }
        return ret;
    }
};
//逆康托尔运算的另一种实现
class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> numFactorial(n+1,1);
        for(int i = 1;i<=n;i++)
            numFactorial[i] = i*numFactorial[i-1];
        vector<int> digit;
        for(int i = 1;i<=n;i++)
            digit.push_back(i);
        string ret = "";
        k -= 1;//需要减去自身,得到的才是这个排列所对应的康托尔展开值
        for(int i = n - 1; i >= 0; --i)
        {//从高位到低位进行寻找
            int index = k / numFactorial[i];
            k = k % numFactorial[i];
            ret +=to_string(digit[index]);
            auto iter = digit.begin()+index;
            digit.erase(iter);//把用过的元素都删除掉，剩下的都是没有用过的
        }
        return ret;
    }
};