class Solution {
public:
    int findTotalH(vector<int>& piles, int hourly) {
        int totalH = 0;
        for(int i=0; i < piles.size(); i++) {
            totalH += ceil((double) piles[i] / (double) hourly);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
     int low = 1;
     int high = *max_element(piles.begin(), piles.end());

     while(low <= high) {
        int mid = low + (high - low) / 2;

        int totalH = findTotalH(piles, mid);

        if(totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
     }
     return low;
    }
};
