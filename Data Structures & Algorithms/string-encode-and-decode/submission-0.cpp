class Solution {
public:

    string encode(vector<string>& arr) {
        string encoded = "";

        for (auto &a : arr) {
            encoded += to_string(a.size()) + "/:" + a;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Find '/'
            while (s[j] != '/') {
                j++;
            }

            // Get length
            int len = stoi(s.substr(i, j - i));

            // Skip '/:'
            j += 2;

            // Extract string
            ans.push_back(s.substr(j, len));

            // Move to next encoded string
            i = j + len;
        }

        return ans;
    }
};
