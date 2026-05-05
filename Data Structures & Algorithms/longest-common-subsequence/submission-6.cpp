class Solution {
    int opt_dp_bottom_up(string_view text1, string_view text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> dp(m+1, 0);
        for (int i = 0; i < n; i++) {
            vector<int> currRow(m+1, 0);
            for (int j = 0; j < m; j++) {
                if (text1[i] == text2[j]) {
                    currRow[j+1] = 1 + dp[j];
                } else {
                    currRow[j+1] = max(currRow[j], dp[j+1]);
                }
            }
            dp = currRow;
        }
        return dp.back();
    }

  public:
    int longestCommonSubsequence(string text1, string text2) {
        return opt_dp_bottom_up(text1, text2);
    }

};
