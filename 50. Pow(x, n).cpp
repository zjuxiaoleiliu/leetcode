题目描述:

Implement pow(x, n).

class Solution {
public:
    double myPow(double x, int n) {

        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        unsigned absn = abs((long)n);
        double absResult = 1;
        if(absn%2 == 1)
            {   
                double temp = pow(x,(absn-1)/2);
                absResult = x*temp*temp;
            }
        else
        {
            double temp = pow(x,absn/2);
            absResult = temp*temp;
        }

        if(n > 0)
            return absResult;
        else 
            return 1/absResult;       
    }
};