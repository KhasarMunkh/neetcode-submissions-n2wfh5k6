class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (auto str : strs) {
            vector<int> count(26, 0);
            for (char ch : str) {
                count[ch-'a']++;
            }

            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++) {
                key += ',' + to_string(count[i]);
            }
            mp[key].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& pair : mp) {
            result.push_back(pair.second);
        }

        return result;
        
    }
};
