class Solution {
private: 

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> cache(n+1, vector<int>(m+1, 0));
        for (int i = 0; i < m; i++) {
            cache[0][i+1] = 1 + cache[0][i];
        }
        for (int i = 0; i < n; i++) {
            cache[i+1][0] = 1 + cache[i][0];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word1[i] == word2[j]) {
                    cache[i+1][j+1] = cache[i][j];
                } 
                else {
                    cache[i+1][j+1] = 1 + min(cache[i][j],min(cache[i][j+1],cache[i+1][j]));
                }
            }
        }

        return cache[n][m];
    }
};
