class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> copy{heights.begin(), heights.end()};
        sort(copy.begin(), copy.end());
        int n=copy.size();
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(copy[i]!=heights[i]) ans++;
        }
        return ans;
    }
};