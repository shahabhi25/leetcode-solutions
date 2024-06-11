bool cmp(vector<int> &a, vector<int> &b)
{
    if(a[1]==b[1])
        return a[0]<b[0];
    return a[1]<b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int ans=0;
        int end=INT_MIN;

        for(auto i:intervals)
        {
            if(end<=i[0]) end=i[1];
            else ans++;
        }
        return ans;
    }
};