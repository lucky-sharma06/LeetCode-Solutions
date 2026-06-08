#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            int y = target - nums[i];

            if(m.find(y) != m.end()){
                return {m[y], i};
            }
            m[x] = i;
        }
        return {};
    }
};