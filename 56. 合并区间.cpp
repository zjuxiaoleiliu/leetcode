题目描述:

Given a collection of intervals, merge all overlapping intervals.

For example,
Given[1,3],[2,6],[8,10],[15,18],
return[1,6],[8,10],[15,18].

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {//由于参数是结构类型，所以用了引用类型(防止不必要的复制造成的的内存消耗)，
public:        //由于我们只是排序,不改变参数，所以用了常量        
    static bool cmp(const vector<int> &one,const vector<int> &two)
    {
        return one[0]<two[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ret;
        if(intervals.size() == 0)
            return ret;
        if(intervals.size() == 1)
        {
            ret.push_back(intervals[0]);
            return ret;
        }

        sort(intervals.begin(),intervals.end(),cmp);
        vector<int> first = intervals[0];
        for(int i =1;i<intervals.size();i++)//遍历，流式处理
        {
            vector<int> two = intervals[i];
            if(two[0]>first[1])
            {
                ret.push_back(first);
                first = two;
            }
            else
                first[1] = max(first[1],two[1]);
        }

        ret.push_back(first);
        return ret;
        
    }
};