class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> seen_s(26, 0);
        vector<int> seen_t(26, 0);
        for (char ch : s) {
            seen_s[ch-'a']++;
        }
        for (char ch : t) {
            seen_t[ch-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (seen_s[i] != seen_t[i]) {
                return false;
            }
        }
        return true;
    }
};
