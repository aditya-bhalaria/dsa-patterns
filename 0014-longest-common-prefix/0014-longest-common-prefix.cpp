class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string store="";
        sort(strs.begin(),strs.end());
        for(int i=0;i<strs[0].length();i++){
            if(strs[0][i]==strs[strs.size()-1][i]){
                store+=strs[0][i];
            }
            else{
                return store;
            }
        }
        return store;
    }
};