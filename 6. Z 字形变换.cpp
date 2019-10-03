题目描述:
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G


//找到每一行的元素在原字符串中的下标位置映射规律，一行一行的
//获取,每一行的元素直接计算出来
class Solution {
public:
    string convert(string s, int nrows)
    {   
    	if(s.length() == 0)
    		return "";
        if(nrows <= 1)
            return s;
        string ret = "";
        int len = s.length();
        for(int i = 0; i < nrows; i++)
        {
            int cur = i;//初始化为这一行的第一个元素位置下标
            if(i == 0 || i == nrows-1)
            {    
            	while(cur < len)
                {
                    ret += s[cur];
                           //以“竖线的末端元素”为中间媒介比较对象
                    cur += 2*(nrows-1);//位移(行下标与行下标之间的位移)不变性的应用
                }
            }
            else
            {	
            	int flag = 0;
            	while(cur < len)
            	{
            		ret += s[cur];
            		if(flag == 0)
            			cur += 2 * (nrows-1-i);
            		else
            			cur += 2 * i;
                    flag = 1-flag;
                }
            }
        }
        
        return ret;
    }
};


//方法2：需要一个额外的辅助空间，按照题目的意思，将原字符串中的
//字符按照z字型写入这个辅助空间中，然后按照拼接即得出要求的字符串

//行数为nRows的时候 周期cycle= 2*nRows-2(一个周期有这么多个数)
//[0，nRows-1]向下, [nRows,cycle)向上
//初始化一个nRows行的vector,依次将string中的每一个元素放入，再一行一行的合并。
 
 class Solution {
 public:
    string convert(string s, int nRows) {

    	if(s.length() == 0)
    		return "";
        if(nRows <= 1)
            return s;       
        int cycle = nRows + nRows - 2; //求出循环周期       
        vector<string> temp(nRows,"");
        for(int i = 0; i < s.length(); i++)//流式处理，一个一个的放
        {
            //i这里的含义是下标，除以周期，得到的是一个周期中以0为起始下标的下标
        //如果i的含义为以1为起始点的第几个数，除以周期，得到的是还剩几个数(从计数意义上说)
        	int index = i%cycle;
            if(index < nRows)  
            	temp[index]+=s[i];//往下走
            else//位移不变性           
            	temp[(nRows-1)-(index-(nRows-1))]+=s[i];//往上走
        }

        string ret="";
        for(int i = 0; i < nRows; i++)
        ret += temp[i];   //合并
         return ret;
     }
 };

 //和上面同样的思路，但是使用了不同的实现

class Solution {
public:
    string convert(string s, int nRows)
    {

    	if(s.length() == 0)
    		return "";
        if(nRows <= 1)
            return s;
        vector<string> temp(nRows,"");
        int len=s.length();      
        int i=0;
        while(i<len)//这里外面的循环是如果还有元素时就一个周期一个周期的添加
        {         //(上面的实现是一个元素一个元素的添加)
            for(int j=0;j<nRows && i<len;j++)           
                temp[j]+=s[i++];
            for(int j=nRows-2;j>0 && i<len;j--)
                temp[j]+=s[i++];
        }
        string ret="";
        for(int i=0;i < nRows;i++)
            ret+=temp[i];
        return ret;
    }
};