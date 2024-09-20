class Solution {
public:
    string shortestPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        string combined = s + "#" + s2;  // Combine with a separator
        int n = combined.size();
        
        // Build the LPS (Longest Prefix Suffix) array
        vector<int> lps(n, 0);
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            lps[i] = j;
        }

        // The length of the longest palindromic prefix
        int maxLen = lps.back();
        string prefixToAdd = s2.substr(0, s.size() - maxLen);
        
        return prefixToAdd + s;  // Construct the shortest palindrome
    }
};
