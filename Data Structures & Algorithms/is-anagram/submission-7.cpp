class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> seen(26, 0);
        
        for (int i = 0; i < s.length(); i++) {
            seen[s[i]-'a']++;
            seen[t[i]-'a']--;
        }

        for (int val : seen) {
            if (val != 0) {
                return false;
            }
        }
        return true;
    }
};
