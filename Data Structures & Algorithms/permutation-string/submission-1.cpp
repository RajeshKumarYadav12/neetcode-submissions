class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1l = s1.size();
        int s2l = s2.size();

        if(s1l > s2l) {
            return false;
        }
        vector<int>s1_hash(26, 0);
        vector<int>s2_hash(26, 0);

        // first window size operations
        int left = 0, right = 0;
        while(right < s1l) {
            s1_hash[s1[right]-'a']++;
            s2_hash[s2[right]-'a']++;
            right++;
        }

        right -= 1; // move right pointer to end of the window 
        while(right < s2l) {
            if(s1_hash == s2_hash) {
                return true;
            }
            right++;
            if(right != s2l) {
                s2_hash[s2[right] - 'a']++;
            }
            s2_hash[s2[left] - 'a']--;
            left++;
        }

        return false;
    }
};
