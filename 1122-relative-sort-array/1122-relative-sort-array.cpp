class Solution {
public:
    unordered_map<int, int> mp;

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr2.size();
        
        for(int i=0; i<n; i++)
        {
            mp[arr2[i]] = i;
        }
        
        auto cmp = [this](int a, int b) {
            auto itA = mp.find(a);
            auto itB = mp.find(b);
            if (itA != mp.end() && itB != mp.end())
                return itA->second < itB->second;
            if (itA != mp.end())
                return true;
            if (itB != mp.end())
                return false;
            return a < b;
        };
        
        sort(arr1.begin(), arr1.end(), cmp);
        return arr1;
    }
};