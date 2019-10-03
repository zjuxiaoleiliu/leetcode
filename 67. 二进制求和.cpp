题目描述:

Given two binary strings, return their sum (also a binary string).

For example,
a ="11"
b ="1"
Return "100".

class Solution {
public:
    string addBinary(string a, string b) {
        
        if(a.length() == 0)
        	return b;
        if(b.length() == 0)
        	return a;

    	string ret;
    	int i = a.length()-1;
    	int j = b.length()-1;
    	int carry = 0;
    	while(i>=0 || j>=0 || carry>0)
    	{
    		int sum = carry;

    		if(i>=0)
    		{
    			sum+=(a[i]-'0');
                i--;
            }

            if(j>=0)
            {
                sum+=(b[j]-'0');
                j--;
            }

            carry = sum/2;
            ret = char('0'+sum%2)+ret;
                  //或者可以使用C++风格：ret = to_string(sum%2)+ret;
    	}

    	return ret;
       
    }
};

