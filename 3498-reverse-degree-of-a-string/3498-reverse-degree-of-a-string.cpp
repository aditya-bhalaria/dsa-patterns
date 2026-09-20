class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char,int>mp;
        char ch='a';
        for(int i=0 ; i<26 ; i++){
            mp[ch++]=26-i;
        }

        int sum=0;
        int indx=1;
        for(char ch: s){
            sum+=(mp[ch]*indx++);
        }
        return sum;
    }
};