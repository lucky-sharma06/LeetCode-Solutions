class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int counter = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = 0; 
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                if(sum == k) counter++;
            }
        }
        return counter;
    }
};