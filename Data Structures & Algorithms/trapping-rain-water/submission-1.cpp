class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> maxLeft(n);
        vector<int> maxRight(n);

        // Store the maximum height from the left up to each index
        int leftMax = 0;
        for (int i = 0; i < n; i++) {
            leftMax = max(leftMax, height[i]);
            maxLeft[i] = leftMax;
        }

        // Store the maximum height from the right up to each index
        int rightMax = 0;
        for (int i = n - 1; i >= 0; i--) {
            rightMax = max(rightMax, height[i]);
            maxRight[i] = rightMax;
        }

        // Calculate trapped water at each index
        int totalWater = 0;

        for (int i = 0; i < n; i++) {
            int waterLevel = min(maxLeft[i], maxRight[i]);
            int trappedWater = waterLevel - height[i];

            totalWater += trappedWater;
        }

        return totalWater;
    }
};