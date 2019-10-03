题目描述:

Given a string S and a string T, find the minimum window 
in S which will contain all the characters 
in T in complexity O(n).

For example,
S ="ADOBECODEBANC"
T ="ABC"

Minimum window is"BANC".

Note: 
If there is no such window in S that covers 
all characters in T, return the emtpy string"".

If there are multiple such windows, you are guaranteed 
that there will always be only one unique minimum window in S.


提示1:
Use two pointers to create a window of letters in S, 
which would have all the characters from T.
提示2：
Since you have to find the minimum window in S 
which has all the characters from T, you need to expand 
and contract(收缩) the window using the two pointers and keep checking 
the window for all the characters. 
This approach is also called Sliding Window Approach. 

L ------------------------ R , 
Suppose this is the window that contains all characters of T                    
L----------------- R , this is the contracted window. 
We found a smaller window that still contains all the characters in T

When the window is no longer valid, start expanding again 
using the right pointer. 

/*
这道题的思路是： 
1) left开始指向 0， right一直后移，直到right - left区间包含T中所有字符。 
记录窗口长度d 
2) 然后left开始后移移除元素，直到移除的字符后窗口中不再包含T中全部的字符时停止
此时T中有一个字符没被包含在窗口中， 
3) 继续后移right，直到T中的所有字符被包含在窗口，重新记录最小的窗口d。 
4) 如此循环直到S中的最后一个字符。 
时间复杂度为O(n)

其实由于子串的左端确定了，以这个左端为起点，包含T的最小子串也就确定了，
所以我们可以以左端为枚举对象，确定所有的满足条件的子串
当开始遍历下一个左端时，right不必从right=这个当前的左端left开始，我们可以
根据上一个成功的窗口right的位置开始向后移动，根据上一个成功的窗口里的信息，
这个right之前的位置作为当前left窗口的right位置是绝对不可能满足条件的
我们只能从这个right位置之后的位置移动

通过分析得出的窗口两个指针的移动规律为：收缩左指针，扩展右指针
*/

/*
每个字符的计数为正说明当前滑动窗口针对这个字符还缺少的个数，为0
说明当前窗口中针对这个字符数量正好够，为负说明当前滑动窗口中针对这个字符
的数量是有剩余的，多余的数量为这个负数的绝对值
数量多余向下向负方向延伸计数，比如说，字符a在映射m中的计数值为4，说明当前窗口
中针对字符a还缺少4个，字符b在映射m中的计数值为0，说明当前滑动窗口中针对字符b
的数量正好够，字符c在映射m中的计数值为-6，说明当前滑动窗口中针对字符c
的数量不但够，满足要求，而且还多出了6个
这种针对字符数量资源的计数表示方法类似于操作系统中信号量中资源的计数表示
*/
class Solution {
public:
    string minWindow(string S, string T) {

        if(T.size() > S.size()) 
        	return "";       
        unordered_map<char, int> m;//映射值为窗口中还需要的这个字符的个数
        for(int i = 0; i < T.size(); ++i) 
        {
        	if(m.find(T[i]) == m.end()) 
        		m[T[i]] = 1;
            else 
            	m[T[i]]++;
        }
        string ret = "";
        int left = 0;
        int cnt = 0;
        int minLen = S.size() + 1;
        for(int right = 0; right < S.size(); ++right) 
        {
        	if(m.find(S[right]) != m.end())
        	{
        		m[S[right]]--;
                if(m[S[right]] >= 0)//说明递减之前计数值>=1 
                    cnt++;//触发cnt状态的改变
            }
            while(cnt == T.size()) 
            {
                if(right - left + 1 < minLen) 
                {
                    minLen = right - left + 1;
                    ret = S.substr(left, minLen);
                }
                if(m.find(S[left]) != m.end()) 
                {
                    m[S[left]]++;//更新计数值
                    if(m[S[left]] > 0) 
                        --cnt;//触发cnt状态的改变
                }
                //进行left左端的下一个遍历
                ++left;//这个是公共操作
            }
           
        }
        return ret;
    }
};

//这道题也可以不用HashMap，直接用个int的数组来代替，因为ASCII只有256个字符，
//所以用个大小为256的int数组即可代替HashMap，
//但由于一般输入字母串的字符只有128个(从128 到255为扩展ASCII 字符)，
//所以也可以只用128，其余部分的思路完全相同

class Solution {
public:
    string minWindow(string S, string T) {

        if(T.size() > S.size()) 
        	return "";       
        vector<int> m(128, 0);
        for(int i = 0; i < T.size(); ++i)
        	m[T[i]]++;
        string ret = "";
        int left = 0;
        int cnt = 0;
        int minLen = S.size() + 1;
        for(int right = 0; right < S.size(); ++right) 
        {
            m[S[right]]--;
            if(m[S[right]] >= 0)
                cnt++;
            while(cnt == T.size()) 
            {
                if(right - left + 1 < minLen) 
                {
                    minLen = right - left + 1;
                    ret = S.substr(left, minLen);
                }
                m[S[left]]++;//不在窗口中的无用字符，顶多只能增长到0为止
                if(m[S[left]] > 0) 
                	--cnt;    
                ++left;                
            }
        }
        return ret;
    }
};
