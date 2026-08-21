class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;        // Deque to store indices of elements
        vector<int> ans;      // Stores maximum of each sliding window

        for (int i = 0; i < nums.size(); i++) {

            // Step 1: Remove indices that are out of the current window
            // If the front index is i-k, it means it is no longer in window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Step 2: Maintain decreasing order in deque
            // Remove all elements smaller than current element from the back
            // because they can never be the maximum for future windows
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Step 3: Add current index to the deque
            dq.push_back(i);

            // Step 4: Once the first window is complete,
            // the front of deque contains the index of maximum element
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;   // Return all window maximums
    }
};
