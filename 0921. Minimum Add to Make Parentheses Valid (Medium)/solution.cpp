class Solution {
public:
    int minAddToMakeValid(string s) {
        int depth = 0;
        int ans = 0;
        for(auto& i : s){
            if(i=='('){
                depth++;
            } else {
                if(depth > 0){
                    depth--;
                } else {
                    ans++;
                }
            }
        }
        return ans + depth;
    }
};