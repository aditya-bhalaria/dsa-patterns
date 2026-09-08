class Solution {
public:
    int countCommas(int n) {
        if(n < 1000) return false;
        int cnt=0;
        int i=1000;
        while(i <= n){
            cnt++;
            i++;
        }
        return cnt;
    }
};