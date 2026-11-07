class Solution {
public:
    string removeKdigits(string num, int k) {
        int range=k;
      if(num.length()==k) return "0";

      stack<char>st;
      string ans;

      for(int i=0 ; i<num.length() ; i++){
        while(!st.empty() && st.top()>num[i] && range > 0){
            st.pop();
            range--;
        }

        st.push(num[i]);

      }
        while(!st.empty() && range>0){
            st.pop();
            range--;
        }
        if(st.empty()) return "0";

        while(!st.empty()){
            ans+=st.top();st.pop();
        }
        while(!ans.empty() && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans.length()==0) return "0";
        reverse(ans.begin(),ans.end());

        return ans;
    }
};