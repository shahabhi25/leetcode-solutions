class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int> nge(n);
        stack<int> st;
        unordered_map<int, int> mp;
        
        int m=nums1.size();
        vector<int> ans(m);
        for(int i=0; i<n; i++)
        {
            mp[nums2[i]]=i;
        }
        for(int i=n-1; i>=0; i--)
        {
            if(st.empty()) nge[i] = -1;
            else
            {
                while(!st.empty() && st.top()<=nums2[i]) st.pop();
                
                if(st.empty()) nge[i] = -1;
                else nge[i] = st.top();
            }
            st.push(nums2[i]);
        }
        
        for(int i=0; i<m; i++)
        {
            ans[i] = nge[mp[nums1[i]]];
        }
        return ans;
    }
};


// [4, 3, 2, 1, 5, 6]
// [5, 5, 5, 5, 6,-1]