class Solution {
public:
    int myAtoi(string s) {
        long long kickstart=0,ans=0,sign=1;
        for(int space=0;space<s.length();space++){
            if(s[space]==' '){
             kickstart++;
            }
            else break;
        }
        if(kickstart<s.length() && s[kickstart]=='-'){
            sign=-1; kickstart++;
        }
        else if(kickstart<s.length() && s[kickstart]=='+'){
            sign=1;
            kickstart++;
        }
       while(kickstart<s.length()){
        if(isdigit(s[kickstart])){
        ans=(ans*10)+(s[kickstart]-'0');
        
        if(sign==1 && ans>INT_MAX){
            return INT_MAX;
        }
        else if(sign==-1 && -ans<INT_MIN){
            return INT_MIN;
        }
        else{
            kickstart++;
        }
        
     }
     else{
        break;
     }
}
return sign*ans;
        }
    
};