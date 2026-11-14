class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        string ans;
        for(int i=0 ;i<s.length() ; i++){
          if(s[i]!='*') st.push(s[i]);
          else{
            st.pop();
          }
        }
        if(st.empty()) return "";
        while(!st.empty()){
            ans+=st.top();st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};