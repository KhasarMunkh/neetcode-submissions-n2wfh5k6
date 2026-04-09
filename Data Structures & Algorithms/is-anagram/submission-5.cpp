class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> seen(26, 0);
        for (char ch : s) {
            seen[ch-'a']++;
        }
        for (char ch : t) {
            seen[ch-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (seen[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
