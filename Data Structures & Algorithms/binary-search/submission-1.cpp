class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = left + (right - left) / 2;
        
        while(left <= right) {
            if(nums[mid] < target) {
                mid = right--;
            }
            else if(nums[mid] > target) {
                mid = left++;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};
