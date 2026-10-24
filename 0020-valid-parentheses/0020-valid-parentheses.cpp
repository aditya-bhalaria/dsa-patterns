class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char iter: s){
            if((iter=='(') || (iter=='{') || (iter=='[')){
                st.push(iter);
            }
            else{
                if(!st.empty()){

                if((iter==')' && st.top()=='(') || (iter==']' && st.top()=='[') || (iter=='}' && st.top()=='{')){
                    st.pop();
                }
                else{
                    return false;
                }
                }
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};