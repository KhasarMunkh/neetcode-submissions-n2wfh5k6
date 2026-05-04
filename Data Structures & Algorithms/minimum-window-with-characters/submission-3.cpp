class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        unordered_map<char,int> window;
        for (const auto& ch : t) {
            need[ch]++;
        }
        int formed = 0;
        int required = need.size();

        int minLength = INT_MAX;
        int bestStartingIndex = -1;

        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            char ch = s[r];
            if (need.contains(ch)) {
                window[ch]++;
                if (window[ch] == need[ch]) {
                    formed++;
                }
            }
            // while our window is valid
            while (formed == required) { 
                int currLength = r - l + 1; 
                if (currLength < minLength) {
                    minLength = currLength;
                    bestStartingIndex = l;
                }
                // now shrink from left
                char lch = s[l];
                if (need.contains(lch)) {
                    window[lch]--;
                    if (window[lch] < need[lch]) {
                        formed--;
                    }
                }
                l++;
            }
        }
        return (minLength == INT_MAX) ? "" : s.substr(bestStartingIndex, minLength);
    }
};
