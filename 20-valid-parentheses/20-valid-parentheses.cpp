class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> ss;
        int n=s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                ss.push(s[i]);
            }
            if(s[i]==')')
            {
                if(!ss.empty() && ss.top()=='(') ss.pop();
                else return false;
            }
            if(s[i]=='}')
            {
                if(!ss.empty() && ss.top()=='{') ss.pop();
                else return false;
            }
            if(s[i]==']')
            {
                if(!ss.empty() && ss.top()=='[') ss.pop();
                else return false;
            }
        }
        
        if(ss.empty()) return true;
        else return false;
        
    }
};