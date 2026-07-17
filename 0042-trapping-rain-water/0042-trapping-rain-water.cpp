class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int n = height.size();
        int r = n - 1;

        int lMax = 0;
        int rMax = 0;
        int total = 0;

        while(l <= r){
            if(height[l] > height[r]){
                // right ko process karenge
                if(height[r] < rMax){
                    // water store hoga
                    total += rMax - height[r];
                }
                else{
                    // paani bah jayega means itself is max
                    rMax = height[r];
                }
                r--;
            }
            else{
                // height[l] <= height[r]
                if(height[l] < lMax){
                    // water store hoga
                    total += lMax - height[l];
                }
                else{
                    // itself is max
                    lMax = height[l];
                }
                l++;
            }
        }
        return total;
    }
};