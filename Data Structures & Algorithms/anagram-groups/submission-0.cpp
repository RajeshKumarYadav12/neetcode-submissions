class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<vector<int>, vector<string>> mp;

        for(auto s : strs) {
            vector<int>v(26, 0);
            for(auto ch : s) {
                v[ch-'a']++;
            }
            mp[v].push_back(s);
        }

        for(auto m : mp) {
            ans.push_back(m.second);
        }
        return ans;
    }
};
