class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor){
            return 1;
        }
       long long sign=1;
       if(dividend<0 && divisor<0){
        sign=1;
       }
       else if(dividend>0 && divisor>0){
        sign=1;
       }
       else{
        sign=-1;
       }

        long long ans=0;
        long long temp = llabs((long long)dividend);
        long long temp2 = llabs((long long)divisor); 
        while(temp>=temp2){
            long long multiple=temp2;
            long long mul=1;
            
           while(multiple+multiple<=temp){
            multiple+=multiple;
            mul+=mul;
           }
           temp-=multiple;
           ans+=mul;
        }
       
        if(sign==-1){
            ans=-ans;
        }
        if(ans<INT_MIN){
            return INT_MIN;
        }
        if(ans>INT_MAX){
            return INT_MAX;
        }

        return ans;
    }
};