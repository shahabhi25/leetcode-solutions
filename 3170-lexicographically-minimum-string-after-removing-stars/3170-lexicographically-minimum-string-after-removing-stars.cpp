class ComparisonClass {
public:
    bool operator() (pair<char, int> a, pair<char, int> b) {
        //comparison code here
        if (a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    }
};

class Solution {
public:
    bool cmp(pair<char, int> a, pair<char, int> b)
    {
        return a.first>b.first;
    }
    string clearStars(string s) {
        int n=s.size();
        priority_queue<pair<char, int>, vector<pair<char, int>>, ComparisonClass > min_heap;
        unordered_set<int> removed_chars;
        string ans="";
        for(int i=0; i<n; i++)
        {
            if(s[i]=='*')
            {
                removed_chars.insert(min_heap.top().second);
                min_heap.pop();
            }
            else
            {
                min_heap.push(make_pair(s[i], i));
            }
        }
        
        for(int i=0; i<n; i++)
        {
            if(removed_chars.find(i)==removed_chars.end() && s[i]!='*')
            {
                ans += s[i];
            }
        }
        return ans;
    }
};