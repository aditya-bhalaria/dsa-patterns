long long mod=1e9+7;
class Solution {
public:
    long long power(long long x,long long y){
        if(y==0) return 1;
        long long half=power(x,y/2);

        if(y%2==0){
           return (half*half)%mod;
        }

        return (half*half*x)%mod;
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=(n)/2;
        return ((power(5,even))*(power(4,odd)))%mod;
        
    }
};