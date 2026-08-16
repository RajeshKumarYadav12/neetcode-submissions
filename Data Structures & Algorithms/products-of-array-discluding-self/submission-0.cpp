class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size());
        int forwardProduct = 1;
        for(int i=0; i<nums.size(); i++) {
            ans[i] = forwardProduct;
            forwardProduct *= nums[i];
        }
        int backwardProduct = 1;
        for(int i=nums.size()-1; i>=0; i--) {
            ans[i] *= backwardProduct;
            backwardProduct *= nums[i];
        }

        return ans;
    }
};
