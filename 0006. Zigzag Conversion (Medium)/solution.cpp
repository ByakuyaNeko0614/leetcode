class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        int n = s.size();
        string ans;
        vector<string> formatting(numRows);
        for(int i = 0; i < n;){
            for(int j = 0; j < numRows && i < n; j++){
                formatting[j].push_back(s[i++]);
            }
            for(int j = numRows-2; j > 0 && i < n; j--){
                formatting[j].push_back(s[i++]);
            }
        }
        for(int i = 0; i < numRows; i++){
            for(auto& element : formatting[i]) ans += element;
        }
        return ans;
    }
};