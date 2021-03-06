题目描述:

以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，
将其转换为规范路径。
在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；
此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；
两者都可以是复杂相对路径的组成部分。
更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径
请注意，返回的规范路径必须始终以斜杠 / 开头，
并且两个目录名之间必须只有一个斜杠 /。
最后一个目录名（如果存在）不能以 / 结尾。
此外，规范路径必须是表示绝对路径的最短字符串。

示例 1：

输入："/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。
示例 2：

输入："/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
示例 3：

输入："/home//foo/"
输出："/home/foo"
解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
示例 4：

输入："/a/./b/../../c/"
输出："/c"
示例 5：

输入："/a/../../b/../c//.//"
输出："/c"
示例 6：

输入："/a//b////c/d//././/.."
输出："/a/b/c"


//  /表示根目录,/也用于目录间的分隔,两个/ /之间的目录项

/*思路：直接做，流式处理，边做边整理
这个思路没有通过提交(原因是文件名中可能会有.字符,
带有.字符的文件名仍然是合法的文件名)，
另外这个方法中间要做的修改处理太多，不如用栈
最后做的工作都是必须的，没有额外的修改动作
*/




class Solution {
public:
	string simplifyPath(string path) {
        
        int n = path.length();
        if(n==0)
        	return "/";
		stack<string> s;//栈s中的元素为两个/ /之间的字符条目,即目录名
        for(int i=0;i<n;i++)
        {
        	while(i<n && path[i]=='/') i++;
            if(i == n) 
            	break;
            string temp;
            while(i<n && path[i]!='/')//取出两个/  /之间的目录名
            {
            	temp+=path[i];
            	i++;
            }
            //对本次取出的两个/  /之间的目录名情况进行判断
            if(temp==".") 
            	continue;
            else if(temp=="..")
            {
                if(!s.empty()) //对根目录..不做处理。 
                	s.pop();                  
            }
            else 
            	s.push(temp);
        }
        if(s.size() == 0)
        	return "/";
        string ret = "";
        while(!s.empty())
        {
            ret='/'+s.top()+ret;
            s.pop();
        }      
        return ret;
    }
};