class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>st(nums.begin(), nums.end());
        int n = st.size();

        return n == nums.size() ? false : true;
    }
};