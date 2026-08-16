class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";

        for(char c : s) {
            if(isalnum(c)) {
                newStr += tolower(c);
            }
        }
        string rev = newStr;
        reverse(rev.begin(), rev.end());
        return rev == newStr;
    }
};
