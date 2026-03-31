class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = INT_MAX;

        int l = 0;
        int r = 0;

        int currLength;
        int curSum = nums[0];
        while (r < nums.size()) {
            while (target <= curSum) {
                currLength = r - l + 1;
                length = min(length, currLength);
                curSum -= nums[l];
                l++;
            }
                r++;
                curSum += nums[r];
        }
        
        
        return (length == INT_MAX) ? 0 : length;
    }
};