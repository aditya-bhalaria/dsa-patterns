class Solution {
public:
    bool isValid(string s) {

        while (!s.empty()) {
            bool found = false;
            for (int i = 0; i+1 < s.length(); i++) {

                if ((s[i] == '(' && s[i + 1] == ')') ||
                    (s[i] == '[' && s[i + 1] == ']') ||
                    (s[i] == '{' && s[i + 1] == '}')) {
                    s.erase(i, 2);
                    found = true;
                    break;
                }
            }
            if (found == false)
                return false;
        }

        return true;
    }
};