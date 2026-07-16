class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // optimal approach
        stack<int> st;
        unordered_map<int, int> mp;
        int n = nums2.size();
        // traverse from back
        vector<int> ans;
        // ans is the NGE array
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop(); // st me elemnts hai and chote hai tab tak pop()
            }
            if(st.empty()){
                mp[nums2[i]] = -1;
                // means right me koi large ni
            }
            else{
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;

    }
};