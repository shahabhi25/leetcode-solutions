class Solution {
public:
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    string shortestPalindrome(string s) {
        int n=s.size();
        if(n<2) return s;
        string rs = s;
        reverse(rs.begin(), rs.end());
        string ss = s+'*'+rs;
        vector<int> pi = prefix_function(ss);
        
        int max_palindrome=pi[2*n];
        
        rs = s.substr(max_palindrome);
        reverse(rs.begin(), rs.end());
        return rs+s;
    }
};
