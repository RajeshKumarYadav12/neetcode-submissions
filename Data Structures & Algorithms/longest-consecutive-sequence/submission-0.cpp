class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end()); // O(n)

        int ans = 0;

        for (int num : st) {
            // Only try to build sequence from the start
            if (st.find(num - 1) == st.end()) {
                int current = num;
                int count = 1;

                while (st.find(current + 1) != st.end()) {
                    current++;
                    count++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};
