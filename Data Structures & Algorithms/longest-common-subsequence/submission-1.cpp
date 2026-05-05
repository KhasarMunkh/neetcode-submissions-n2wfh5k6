class Solution {
  private:
    int lcs_dfs(string_view text1, string_view text2, int i, int j, vector<vector<int>> &cache) {
        if (i >= text1.size() || j >= text2.size()) { // out of bounds
            return 0;
        }
        if (cache[i][j] != -1) { // already solved
            return cache[i][j];
        }
        if (text1[i] == text2[j]) { // match!
            cache[i][j] = 1 + lcs_dfs(text1, text2, i + 1, j + 1, cache);
        } else {
            cache[i][j] = max(lcs_dfs(text1, text2, i + 1, j, cache),
                       lcs_dfs(text1, text2, i, j + 1, cache));
        }
        return cache[i][j];
    }

  public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> cache(text1.size(), vector<int>(text2.size(), -1));
        return lcs_dfs(text1, text2, 0, 0, cache);
    }
};
