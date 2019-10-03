题目描述:

Given an array S of n integers, are there elements a, b, c 
in S such that a + b + c = 0? Find all unique triplets in the array 
which gives the sum of zero.

Note:

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.

For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {
        vector<vector<int>> ret;
    	if(num.size()<3)
    		return ret;
        sort(num.begin(),num.end());
        if(num[0]>0 || num[num.size()-1]<0)
        	return ret;
        for(int i = 0;i < num.size();i++)
        {   
        	if(num[i] > 0)
        		break;
            if(i>0 && num[i]==num[i-1])
            	continue;
            int target=-num[i];
            int l = i+1;
            int r = num.size()-1;
            while(l<r)
            {
            	int sum = num[l]+num[r];
                if(sum > target)
                	r--;
                else if(sum < target)
                	l++;
                else
                {
                	vector<int> temp;
                    temp.push_back(num[i]);
                    temp.push_back(num[l]);
                    temp.push_back(num[r]);
                    ret.push_back(temp);
                    l++;r--;
                    while(l<r && num[l]==num[l-1]) l++;
                    while(l<r && num[r]==num[r+1]) r--;
                }
            }
        }
        return ret;    
    }
};