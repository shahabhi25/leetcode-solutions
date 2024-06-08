class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        int m=s.size();
        if(n!=m) return false;
        
        for(int i=0; i<n; i++)
        {
            string temp_s1 = s.substr(i, n-i);
            string temp_s2 = goal.substr(0, n-i);
            
            // cout<<"temp_s1 "<<temp_s1<<" temp_s2 "<< temp_s2<<"\n";
            if(temp_s1==temp_s2)
            {
                string temp_t1 = s.substr(0, i);
                string temp_t2 = goal.substr(n-i, i);
                // cout<<"temp_t1 "<<temp_t1<<" temp_t2 "<< temp_t2<<"\n";
                if(temp_t1==temp_t2) return true;
                else return false;
            }
        }
        return false;
    }
};