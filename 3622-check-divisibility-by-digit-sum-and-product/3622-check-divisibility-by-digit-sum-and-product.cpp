class Solution {
public:
    int DS(int n1){
        int temp=n1;
        int sum=0;
        while(temp!=0){
            sum+=(temp%10);
            temp/=10;
        }
        return sum;
    }

    int DP(int n2){
        int temp=n2;
        int prod=1;
        while(temp!=0){
            prod*=(temp%10);
            temp/=10;
        }
        return prod;
    }
    bool checkDivisibility(int n) {
        int ans=DS(n)+DP(n);
        if(n%ans==0){
            return true;
        }

        return false;
    }
};