class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> l;
        int n = asteroids.size();
        for(int i = 0; i < n; i++){
            if(asteroids[i] > 0){
                // +ve asteroids come
                l.push_back(asteroids[i]);
            }
            else{
                // -ve aaya 
                // while(l.empty() || l.back() < 0){
                //     l.push_back(asteroids[i]);
                // }

                while(!l.empty() && l.back() > 0 && l.back() < abs(asteroids[i])){
                    // smaller getting destroyed by negatives
                    l.pop_back();
                }
                
                if(!l.empty() && l.back() == abs(asteroids[i])){
                    l.pop_back(); // if equal hai then both destryoed so move ahead
                }
                else if(l.empty() || l.back() < 0){
                    l.push_back(asteroids[i]); // -ve to be pushed in the list
                }
            }
        }
        vector<int> ans;
        for(auto val : l){
            ans.push_back(val);
        }
        return ans;
    
    }
};