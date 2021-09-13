class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1.0;
        long long p = n;
        
        if(p < 0)
            p *= -1;
        
        while(p)
        {
            if(p % 2)
            {
                ans = ans * x;
                p--;
            }
            else
            {
                x = x * x;
                p = p / 2;
            }
        }
        
        if(n < 0)
            ans = double(1.0) / (double)(ans);
        
        return ans;
    }
};





// Binary exponentiation

class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1.0;
        long long p = n;
        
        if(p < 0)
            p *= -1;
        
        while(p)
        {
            if(p & 1)
            {
                ans = ans * x;
            }
            
            x = x * x;
            p = p >> 1;
        }
        
        if(n < 0)
            ans = double(1.0) / (double)(ans);
        
        return ans;
    }
};


//https://leetcode.com/problems/powx-n/
