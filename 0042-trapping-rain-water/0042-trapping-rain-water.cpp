class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int prefixMax[n], suffixMax[n];

        prefixMax[0] = height[0];
        for(int i = 1; i < n; i++){
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }
        suffixMax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        int total = 0;
        for(int i = 0; i < n; i++){
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];
            if(height[i] < leftMax && height[i] < rightMax){ // this is even not necessary as where there is no water total += 0; will have no change
                // water is stored on the ith building
                total += min(leftMax, rightMax) - height[i];
            }
        }

        return total;
    }
};