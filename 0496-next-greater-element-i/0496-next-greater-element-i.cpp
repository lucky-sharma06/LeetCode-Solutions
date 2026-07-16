class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;  
        int j = 0;
        vector<int> ans;
        for(i = 0; i < nums1.size(); i++){
            for(j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    break;
                }
            }
            // j mil gya
            j++;
            
            bool found = false; // flag variable
            while(j < nums2.size()){
                if(nums2[j] > nums1[i]){
                    ans.push_back(nums2[j]);
                    found = true;
                    break;
                }
                else
                    j++;
            }
            if(!found){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};