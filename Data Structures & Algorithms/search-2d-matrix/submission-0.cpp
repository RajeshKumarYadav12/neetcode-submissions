class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int e = (row * col)-1;

        while(s<=e) {
            int mid = (s+e)/2;
            int ele = matrix[mid / col][mid % col];
            if(ele == target) {
                return 1;
            }
            else if(ele < target) {
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return 0;
    }
};
