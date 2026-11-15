class Solution {
public:
   long long Str2Int(string str){
      long long place=1;
      long long ans=0;
      int i=str.length()-1;
      while(i>=0 && (str[i]>='0' && str[i]<='9')){
        ans+=(place*(str[i]-'0'));place*=10;
        i--;
      }
      if(str[0]=='-') return (ans*-1);
      return ans;
   }

    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        for(int i=0 ; i<tokens.size() ; i++){
          if(!st.empty() && tokens[i]=="+"){
            int num1=st.top();st.pop();
            int num2=st.top();st.pop();
            st.push(num2+num1);
          }
          else if(!st.empty() && tokens[i]=="-"){
            int num1=st.top();st.pop();
            int num2=st.top();st.pop();
            st.push(num2-num1);
          }
          else if(!st.empty() && tokens[i]=="/"){
            int num1=st.top();st.pop();
            int num2=st.top();st.pop();
            st.push(num2/num1);
          }
          else if(!st.empty() && tokens[i]=="*"){
            int num1=st.top();st.pop();
            int num2=st.top();st.pop();
            st.push(num2*num1);
          }
          else{
            st.push(Str2Int(tokens[i]));
          }
        }
       return st.top();
    }
};