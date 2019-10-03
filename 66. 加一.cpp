题目描述:

Given a number represented as an array of digits, plus one to the number.

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {

    	vector<int> ret;
    	int size = digits.size();
    	if(size == 0)
    		return ret;
    	int over = 1;
    	for(int i = size-1;i>=0;i--)
    	{
    		int sum =digits[i]+over;
    		over = sum / 10;
    		sum = sum % 10;
    		ret.insert(ret.begin(),sum);
    	}
        if(over == 1)
            ret.insert(ret.begin(),over);
    	return ret;      
    }
};