class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) 
    {
        int n=points.size();
        unordered_map<string, int> m;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {
                    int distance = (points[i][0]-points[j][0])*(points[i][0]-points[j][0]) +
                        (points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                    string s = to_string(i)+'_'+to_string(distance);
                    m[s]++;
                }
            }
        }
        
        int ans=0;
        for(auto x: m)
        {
            // cout<<x.first<<" "<<x.second<<"\n";
            if(x.second>1)
            {
                ans += (x.second*(x.second-1))/2;
            }
        }
        return 2*ans;
    }
};