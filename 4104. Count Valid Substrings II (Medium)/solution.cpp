class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;
        int n = s.size();
        int po = -1;
        int aa=-1, ba=-1, ca=-1;
        for(int i = 0; i < n; i++){
            if(s[i]=='a') aa=i;
            else if(s[i]=='b'&&aa!=-1) ba=aa;
            else if(s[i]=='c'&&ba!=-1) ca=ba;
            if(ca!=-1) po = ca;
            ans+=abs(i-po);
            /*for(int j = i; j < n; j++){
                ans++;
                if(count==0&&s[j]=='a') count++;
                else if(count==1&&s[j]=='b') count++;
                else if(count==2&&s[j]=='c'){
                    ans--;
                    break;
                }else if(s[j]=='a')count=1;
                else count = 0;
            }*/
        }
    return ans;
    }
};