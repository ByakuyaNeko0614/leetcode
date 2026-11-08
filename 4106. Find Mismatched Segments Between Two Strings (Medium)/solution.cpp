class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.size();
        vector<vector<string>> a;
        string temp1="";
        string temp2="";
        for(int i = 0; i < n; i++){
            if(s1[i]!=s2[i]){
                temp1+=s1[i];
                temp2+=s2[i];
            }else if(!temp1.empty()){
                a.push_back({temp1, temp2});
                temp1="";
                temp2="";
            }
        }
        if(!temp1.empty()){
            a.push_back({temp1, temp2});
            temp1="";
            temp2="";
        }
        return a;
    }
};