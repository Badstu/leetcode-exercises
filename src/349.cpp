class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.empty() || nums2.empty()) return res;

        unordered_set<int> hash;
        unordered_set<int> hash2;

        for(auto x: nums1){
            hash.insert(x);
        }

        for(auto x: nums2){
            if(hash.find(x) != hash.end() && hash2.find(x) == hash.end()){
                res.push_back(x);
            }
            hash2.insert(x);
        }
        return res;
    }
};