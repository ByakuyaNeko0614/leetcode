class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        int n = types.size();
        int gn = groupSize.size();
        int need = 0;
        vector<int> st;
        vector<int> count;
        for(int i = 0; i < n; i++){
            if(!st.empty()&&types[st.back()]==types[i]&&colors[st.back()]==colors[i]){
                count.back()++;
            } else st.push_back(i), count.push_back(1);
            if(count.back()==groupSize[types[i]]){
                count.pop_back();
                st.pop_back();
            }
        }
        return st.empty();
    }
};