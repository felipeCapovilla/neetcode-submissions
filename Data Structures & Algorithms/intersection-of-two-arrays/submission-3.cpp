class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int>v1 (nums1.begin(),nums1.end());
        unordered_set<int> v2;

        for(int n : nums2){
            if(v1.count(n)){
                v2.insert(n);
            }
        }

        return vector<int> (v2.begin(),v2.end());



        
        
    }
};