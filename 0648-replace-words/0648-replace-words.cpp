class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict (dictionary.begin(), dictionary.end());
        
        int n=sentence.size();
        string temp_s = "";
        string ans_s = "";
        for(int i=0; i<n; i++)
        {
            temp_s += sentence[i];
            if(sentence[i]==' ')
            {
                ans_s += temp_s;
                temp_s = "";
            }
            if(dict.find(temp_s) != dict.end())
            {
                while(i<n && sentence[i]!=' ') i++;
                ans_s += temp_s;
                ans_s += " ";
                temp_s = "";
            }
        }
        if(temp_s!="") 
        {
            ans_s += temp_s;
            return ans_s;
        }
        return ans_s.substr(0, ans_s.size()-1);
    }
};