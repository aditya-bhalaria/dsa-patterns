class Solution {
public:
    double ans(double m , int n){
       if(n==0){
        return 1;
       }

       double half=ans(m , n/2);
       if(n%2==0){
         return half*half;
       }
       return half*half*m;
    }
    double myPow(double x, int n) {
        long long N=n;
        if(N<0) return 1.0/ans(x,-N);
        return ans(x,-N);
    }
};