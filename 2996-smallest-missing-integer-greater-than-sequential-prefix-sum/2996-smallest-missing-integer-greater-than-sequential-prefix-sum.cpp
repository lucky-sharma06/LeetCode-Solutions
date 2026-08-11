class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int preSum = nums[0];
        int i = 0;
        for (i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                preSum += nums[i];
            } else {
                break;
            }
        }
        // now i is at the point from where the non sequential elements occur
        unordered_map<int, int> mp;
        // and i will push them in the stack...
        for (int x : nums) {
            mp[x] = 1;
        } // eg[38] 
        int ans = preSum;
        while (mp.find(ans) != mp.end()) {
            // means mp me milgya
            ans++;
        }

        return ans;
    }
};