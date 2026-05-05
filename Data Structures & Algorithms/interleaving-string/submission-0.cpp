class Solution {
  private:
    bool recurse(string_view s1, string_view s2, string_view s3, int i, int j, int k) {
        // Base cases:
        if (k == s3.length()) {
            return (i == s1.length() && j == s2.length());
        }
        if (i < s1.size() && s3[k] == s1[i]) {
            if (recurse(s1, s2, s3, i + 1, j, k + 1)) {
                return true;
            }
        }
        if (j < s2.size() && s3[k] == s2[j]) {
            if (recurse(s1, s2, s3, i, j + 1, k + 1)) {
                return true;
            }
        }
        return false;
    }

  public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        return recurse(s1, s2, s3, 0, 0, 0);
    }
};
