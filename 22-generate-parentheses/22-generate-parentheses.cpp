class Solution {
public:
    void solve(string s, vector<string> &ans, int open, int close, int n)
    {   
        if(open>n || close>n) return;
        if(open==n && close==n)
        {
            ans.push_back(s);
            return;
        }
        else
        {
            if(open>close)
            {
                string s1=s;
                s1+=')';
                solve(s1, ans, open, close+1, n);
            }
            string s2=s;
            s2+='(';
            solve(s2, ans, open+1, close, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        string s="";
        solve(s, ans, 0, 0, n);
        return ans;
    }
};