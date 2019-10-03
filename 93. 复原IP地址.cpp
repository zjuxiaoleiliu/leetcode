题目描述:

Given a string containing only digits, restore(恢复) it by returning 
all possible valid IP address combinations.
For example:
Given"25525511135",
return["255.255.11.135", "255.255.111.35"]. (Order does not matter)


/*
背景知识：
IP地址由32位二进制数组成，为便于使用，常以XXX.XXX.XXX.XXX形式表现，
每组XXX代表小于或等于255的10进制数。所以说总共有四段，
每一段可能有一位，两位或者三位，范围是[0, 255]，
题目明确指出输入字符串只含有数字，所以当某段是三位时，
我们要判断其是否越界（>255)，还有一点很重要的是，
当只有一位时，0可以成某一段，如果有两位或三位时，
像00,01,001,011,000等都是不合法的
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

    	vector<string>ret;
    	if(s.length() < 4)
    		return ret;
    	string temp;
    	restoreIpAddressesCore(s,temp,ret,0);
    	return ret;       
    }

    void restoreIpAddressesCore(string s,string temp,vector<string> &ret,int k)
    {
    	if(k == 3)
    	{
    		if(isValid(s))//当进行到最后一段时就只有一种选择了
    			ret.push_back(temp+s);
    		return;
    	} 
         //枚举当前段的每一种合法字符构成情况，然后深度优先遍历构造下一段
    	for(int i = 1;i<4 && i<s.size();i++)
    	{
    		string sub = s.substr(0,i);
    		if(isValid(sub))
    			restoreIpAddressesCore(s.substr(i),temp+sub+'.',ret,k+1);
    	}

    }

    bool isValid(string s)
    {
    	stringstream ss(s);
        int num;
        ss>>num;//这种利用字符串流得到字符串代表的数值的方法注意一下
        if(s.size()>1)
            return s[0]!='0' && 0<=num && num<=255;
        else
        	return 0<=num && num<=9;
    }
};
