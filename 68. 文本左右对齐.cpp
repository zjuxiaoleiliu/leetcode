题目描述:
Given an array of words and a length L, format 
the text such that each line 
has exactly L characters and is fully 
(left and right) justified.完全左右两边对齐
You should pack your words in a greedy 
approach; that is, pack as many words as 
you can in each line. Pad extra spaces' 'when necessary 
so that each line has exactly L characters.

Extra spaces between words should be distributed 
as evenly(均匀地) as possible. If the number of spaces on 
a line do not divide(分配) evenly between words, 
the empty slots on the left will be assigned more spaces 
than the slots on the right.
For the last line of text, it should be left justified 
and no extra space is inserted between words.
For example,
words:["This", "is", "an", "example", "of", "text", 
"justification."]
L:16.
Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Note: Each word is guaranteed not to exceed L in length.
click to show corner cases.
Corner Cases://极端情况，边界情况
A line other than the last line might contain only one word. 
What should you do in this case?
In this case, that line should be left-justified.

给定一个单词数组和一个长度 maxWidth，重新排版单词，
使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
你应该使用“贪心算法”来放置给定的单词；也就是说，
尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，
使得每行恰好有 maxWidth 个字符。
要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格
不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
文本的最后一行应为左对齐，且单词之间不插入额外的空格。
说明:
单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。


class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {

		vector<string> ret;
		int n = words.size();	 
		if(n == 0) 
			return ret;
		int i = 0;
		while(i < n)
		{
			int j = i;
			int len = 0;
			while(j < n)//这个while循环有两个终止循环的情况，一个好的
			{           //编程习惯是循环中断后应马上判断到底是那种情况发生的中断
				        //针对不同的中断情况分别做不同的处理
				if(len + words[j].length() + j - i > L) 
					break;
				len += words[j].length();
				j++;
			}			
			string line;
			//最后一行
			if(j == n)
			{
				for(int k = i; k < j; k++)
				{
					line = line + words[k];
					if(k != j - 1)
					{
						len++;
						line = line + ' ';
					}
					else
						addSpace(line, L - len);
				}	 
			}
			else
			{
				int totalSpace = L - len;
				if(j-1-i+1 != 1)
				{
					int avg = totalSpace/(j-1-i);//几个格槽相当于向前移动几次,即两个下标之间的位移
					int remain = totalSpace%(j-1-i);
					for(int k = i; k < j-1; k++)
					{
						line = line + words[k];
						if(remain > 0)
							addSpace(line, avg + 1);
						else
							addSpace(line, avg);
						remain--;
					}
					line = line + words[j-1];
				}
				else
				{
					line = line + words[i];
					addSpace(line, totalSpace);
				}

			}
			ret.push_back(line);
			i = j;
		}
		 return ret;
	 }
 
	void addSpace(string & line, int num)
	{
		while(num--)
			line = line + ' ';	 
	}

 };
 