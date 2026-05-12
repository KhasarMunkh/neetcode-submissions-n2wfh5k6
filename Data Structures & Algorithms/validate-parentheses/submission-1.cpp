class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        unordered_map<char,char> mp {
            {'(',')'},
            {'{','}'},
            {'[',']'}
        };
        for (int i = 0; i < s.length(); i++) {
            if (!sk.empty() && mp[sk.top()] == s[i]) {
                sk.pop();
                continue;
            }
            sk.push(s[i]);
        }
        return sk.empty();
    }
};
