class Solution {
public:
/*
    s1 = abc
    a : 1
    b: 1 
    c : 1
    iterate thru s2 
    s2 : lecabee
             ^

*/
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26,0);
        for (const char ch : s1) {
            count1[ch - 'a']++;
        }
        int l = 0;
        int lengthWindow = s1.size();

        vector<int> count2(26,0);

        for (int i  = 0; i < lengthWindow; i++) {
            count2[s2[i]-'a']++;
        }
        if (count2 == count1) {
            return true;
        }
        for (int i = lengthWindow; i < s2.size(); i++) {
            count2[s2[i - lengthWindow] - 'a']--;
            count2[s2[i]-'a']++;
            if (count2 == count1) {
                return true;
            }
        }
        return false;
    }
};
