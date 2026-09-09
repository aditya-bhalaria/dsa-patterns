class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return false;
        long long ans=0;
           long long comma=1;
           long long  i=1000;
           while(i <= n){
           long long end=(i*1000-1);
           if(end > n) end=n;

           ans+=(end-i+1)*comma;
            i*=1000;
            comma++;
           }

       return ans;
    }
};