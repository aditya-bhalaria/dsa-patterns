class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int counter=0;
        for(char ch: s){
            if(ch=='('){
                counter++;
                depth=max(depth,counter);
            }

            else if(ch==')'){
                counter--;
            }
        }
        return depth;
    }
};