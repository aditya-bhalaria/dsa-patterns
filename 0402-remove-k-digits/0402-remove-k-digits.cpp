class Solution {
public:
    string removeKdigits(string num, int k) {
      if(num.length()==k)return "0";
      int remove=k;
      stack<char>st;

      for(int i=0 ; i<num.length() ; i++){
        while(!st.empty() && st.top()-'0'>num[i]-'0' && remove!=0){
          st.pop();
          remove--;
        }
        st.push(num[i]);
      }
      while(remove>0){
         st.pop();remove--;
      }
      // if(st.empty()) return "0";
      string ans="";
      while(!st.empty()){
        ans+=st.top();st.pop();
      }
      while(ans.length()!=0 && ans.back()=='0'){
        ans.pop_back();
      }
      if(ans.length()==0) return "0";
      reverse(ans.begin() , ans.end());
      return ans;
    }
};
