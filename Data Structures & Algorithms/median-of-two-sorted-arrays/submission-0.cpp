class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merge(nums1.size() + nums2.size());

        int i=0, j=0;
        int k=0;

        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i] <= nums2[j]) {
                merge[k++] = nums1[i++];
            }
            else {
                merge[k++] = nums2[j++];
            }
        }
        
        while(i<nums1.size()) {
            merge[k++] = nums1[i++];
        }
        while(j<nums2.size()) {
            merge[k++] = nums2[j++];
        }

        int n = merge.size();

        if(n&1) {
            return double(merge[n/2]);
        }
        else {
            return double(merge[n/2] + merge[n/2-1])/2;
        }
    }
};
