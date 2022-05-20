class Solution {
public:
    void solve(int i, string s, vector<string> &ans, string &digits)
    {
        if(i==digits.size())
        {
            ans.push_back(s);
            return;
        }
        unordered_map<char, pair<int, int>> m;
        m['2']={0, 3};
        m['3']={3, 6};
        m['4']={6, 9};
        m['5']={9, 12};
        m['6']={12, 15};
        m['7']={15, 19};
        m['8']={19, 22};
        m['9']={22, 26};
        
        for(int j=m[digits[i]].first; j<m[digits[i]].second; j++)
        {
            string s1=s;
            s1+=('a'+j);
            solve(i+1, s1, ans, digits);
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        int n=digits.size();
        vector<string> ans;
        if(n==0) return ans;
        string s="";
        solve(0, s, ans, digits);
        return ans;
    }
};