class Solution {
public:
    bool repeatedStringMatch(string a, string b, int x, int y) {
        int asize = a.size();
        int bsize = b.size();
        long long alen = 1LL*asize*x;
        long long blen = 1LL*bsize*y;
        if(blen>alen) return false;
        bool ans = false;
        //find if continuous?
        bool conti = true;
        for(int i = 0; i < asize; i++){
            if(i+blen>alen) break;
            conti = true;
            for(int j = 0; j < min(blen, 2LL*asize*bsize); j++){//TLE?
                if(a[(i+j)%asize]!=b[j%bsize]){
                    conti=false;
                    break;
                }
            }
            if(conti) return true;
        }
        return false;
    }
};