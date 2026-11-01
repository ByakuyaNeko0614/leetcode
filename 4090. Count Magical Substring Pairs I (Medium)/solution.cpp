class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<int>s1(n, 0), s2(n, 0);
            bool visited[26]={0};
            int count = 0;
            for(int j = i; j >= 0; j--){
                if(!visited[s[j]-'a']) visited[s[j]-'a']=true, count++;
                s1[j]=count;
            }
            count = 0;
            for(int j = 0; j < 26; j++) visited[j]=false;
            for(int j = i+1; j < n; j++){
                if(!visited[s[j]-'a']) visited[s[j]-'a']=true,count++;
                s2[j]=count;}
            int check[27]={0};
            for(int j = i+1; j < n; j++){
                check[s2[j]]++;
            }
            for(int j = 0; j <= i; j++){
                ans+=check[s1[j]];
            }
        }
        return ans;
    }
};