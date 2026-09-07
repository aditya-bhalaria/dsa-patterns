class Solution {
public:
    bool isPowerOfTwo(long long n) {
        if(n==0) return false;
        long long p=n-1;
        if((n&p)== 0) return true;
        return false;
    }
};