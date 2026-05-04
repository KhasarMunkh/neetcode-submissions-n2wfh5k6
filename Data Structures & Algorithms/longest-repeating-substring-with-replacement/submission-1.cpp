class Solution {
    int find_max_count(unordered_map<char,int>& count) {
        auto max_pair = max_element(count.begin(), count.end(), 
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            }
        );
        return max_pair->second;
    }
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int res = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;

            //check if current window valid
            while (r-l+1 - find_max_count(count)  > k){
                count[s[l]]--;
                l+=1;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};
