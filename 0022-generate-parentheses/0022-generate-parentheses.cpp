class Solution {
public:
    void GenPara(int n , int open ,int close , string s , vector<string> &ans){
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }

        if(close < open){
           
            GenPara(n,open,close+1,s+')',ans);
        }

        if(open < n){
            GenPara(n,open+1,close,s+"(",ans);
        }
            
    }
    vector<string> generateParenthesis(int n) {
        string str;
        vector <string> v;
        GenPara(n,0,0,str,v);
        return v;
    }
};