class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> buckets(3,0);
        for (int num : nums) {
            buckets[num]++;
        }

        int index = 0;
        for (int i = 0; i < 3; i++) {
            while (buckets[i]-- > 0) {
                nums[index++] = i;
            }
        }
    }
};