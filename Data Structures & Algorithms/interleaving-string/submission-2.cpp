class Solution {
  private:
    bool memo(string_view s1, string_view s2, string_view s3, int i, int j, int k, vector<vector<int>>& cache) {
        // Base cases:
        if (k == s3.length()) {
            return (i == s1.length() && j == s2.length());
        }

        if (cache[i][j] != -1) {
            return cache[i][j];
        }

        bool res = false;
        if (i < s1.size() && s3[k] == s1[i]) {
            res = memo(s1,s2,s3,i+1,j,k+1,cache);
        }
        if (!res && j < s2.size() && s3[k] == s2[j]) {
            res = memo(s1,s2,s3,i,j+1,k+1,cache);
        }
        return cache[i][j] = res;
    }
  public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        vector<vector<int>> cache(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return memo(s1, s2, s3, 0, 0, 0, cache);
    }
};