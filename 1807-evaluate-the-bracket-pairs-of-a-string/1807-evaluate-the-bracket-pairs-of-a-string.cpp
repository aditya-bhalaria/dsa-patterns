class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (int st = 0; st < knowledge.size(); st++) {
            mp[knowledge[st][0]] = knowledge[st][1];
        }
        string ans = "";
        
        
            for(int i=0 ;i<s.length() ; i++){
                string part="";
              if(s[i]!='('){
                ans+=s[i];
              }

              else{
                i++;
                while(s[i]!=')'){
                      part+=s[i];
                      i++;
                }
              if(mp.find(part)!=mp.end()) ans+=mp[part];
              else{
                ans+='?';
                }
              }
            }
        
        return ans;
    }
};