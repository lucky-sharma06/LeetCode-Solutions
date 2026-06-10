class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // optimal approach
        map<int, int> mp;
        int count = 0;
        int prefixSum = 0;
        mp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            int rem = prefixSum - k;
            // check rem in the map
            if(mp.find(rem) != mp.end()){
                // rem is in the map
                count += mp[rem];
            }
            mp[prefixSum]++;
        }

        return count;
    }
};