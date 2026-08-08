class Solution {
public:
    int candy(vector<int>& ratings) {
        // Optimal Approach
        int n = ratings.size();
        int sum = 1;
        int i = 1;
        while(i < n){
            if(ratings[i] == ratings[i - 1]){
                    sum += 1;
                    i++;
                    continue;
            }
            // slope is increasing
            int peak = 1;
            while(i < n && (ratings[i] > ratings[i - 1])){
                peak++; // cause peak 1 is already considered
                sum += peak;
                i++;                
            }
            int down = 1;
            while(i < n && (ratings[i] < ratings[i - 1])){
                sum += down;
                down++;
                i++;
            }

            if(down > peak){
                sum += (down - peak);
            }

        }
        return sum;
    }
};