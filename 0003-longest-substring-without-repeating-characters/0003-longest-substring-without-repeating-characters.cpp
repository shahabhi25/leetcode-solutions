class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        int l=0;
        int r=0;
        unordered_map<char, int> mp;
        int ans =1;
        while(r<n)
        {
            while(mp[s[r]]>0) 
            {
                mp[s[l]]--;
                l++;
            }
            mp[s[r]]++;
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};