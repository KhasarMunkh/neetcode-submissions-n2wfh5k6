class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> buckets(3,0);
        for (int num : nums) {
            buckets[num]++;
        }
        nums.clear();
        for (int i = 0; i < buckets.size(); i++) {
            for (int j = 0; j < buckets[i]; j++) {
                nums.push_back(i);
            }
        }
    }
};