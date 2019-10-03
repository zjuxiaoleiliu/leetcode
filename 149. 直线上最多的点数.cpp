题目描述:

Given n points on a 2D plane, find the maximum number 
of points that lie on the same straight line.
找出在同一条直线上的点的最大个数

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

//对于这个问题要考虑问题全面一些，考虑到重合的点和斜率不存在的情况

class Solution {
public:
    int maxPoints(vector<Point>& points)
    {
        int n = points.size();
        if(n < 2)
            return n;
        int ret = 0;
        for(int i=0;i<n;i++)
        {   //这里无法使用unordered_map,因为pair类型没有默认的哈希函数
            map<pair<int,int>,int> slopeMap;
            //注意这里重合的点按不同的点看待
            int duplicates = 1;//自身重叠初始化为1
            for(int j=i+1;j<n;j++)
            {
                //重合
                if(points[i].x == points[j].x  && points[i].y == points[j].y)
                {
                   duplicates++;
                   continue;
                }
                //斜率不适用float作为键，精度损失，使用除以最小公约数后的pair作为键
                int dix = points[j].x - points[i].x;
                int diy = points[j].y - points[i].y;
                int maxD = gcd(dix,diy);
                slopeMap[{dix/maxD,diy/maxD}] ++;
            }
            ret = max(ret,duplicates);
            for(auto iter=slopeMap.begin();iter!=slopeMap.end();iter++)
                ret = max(ret,iter->second + duplicates);
        }
        return ret;
    }
    int gcd(int a, int b)
    {
        return (b == 0) ? a : gcd(b, a % b);
    }
};