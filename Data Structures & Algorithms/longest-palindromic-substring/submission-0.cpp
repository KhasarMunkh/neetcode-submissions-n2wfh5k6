class Solution {
public:
    string longestPalindrome(string s) {
        int length = 0;
        string longestPal = "";
        for (int i = 0; i < s.size(); i++) {
            // odd length
            int l = i;
            int r = i;
            while (l >= 0 && r < s.size() && s[l]==s[r]) {
                if (r-l+1 > length) {
                    length = r-l+1;
                    longestPal = s.substr(l, length);
                }
                l--;
                r++;
            }
            // even length
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r-l+1 > length) {
                    length = r-l+1;
                    longestPal = s.substr(l, length);
                }
                l--;
                r++;
            }
        }
        return longestPal;
    }
};
