class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>nextGreaterBar(height.size());
        vector<int>prevGreaterBar(height.size());

        int maxi = 0;
        for(int i=0; i<height.size(); i++) {
            maxi = max(maxi, height[i]);
            nextGreaterBar[i] = maxi;
        }

        maxi = 0;
        for(int i=height.size()-1; i>=0; i--) {
            maxi = max(maxi, height[i]);
            prevGreaterBar[i] = maxi;
        }

        int ans = 0;
        for(int i=0; i<height.size(); i++) {
            int h = min(prevGreaterBar[i], nextGreaterBar[i]) - height[i];
            ans += (h * 1);
        }
        return ans;
    }
};
