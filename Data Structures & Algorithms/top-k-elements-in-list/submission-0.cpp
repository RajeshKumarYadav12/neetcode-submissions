class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int>mp;

     for(auto n : nums) {
        mp[n]++;
     }

     priority_queue<pair<int, int>>pq;

     for(auto m : mp) {
        pq.push({m.second, m.first});
     }

     vector<int>ans;
     while(k) {
        int top = pq.top().second;
        ans.push_back(top);
        pq.pop();
        k--;
     }
     return ans;
    }
};
