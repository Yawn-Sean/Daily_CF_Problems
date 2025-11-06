#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MOD = 1000000007;

inline int enc(int a,int b,int c){ return (a*3 + b)*3 + c; }
inline void dec(int idx,int &a,int &b,int &c){
    c = idx % 3; idx /= 3;
    b = idx % 3; idx /= 3;
    a = idx % 3;
}

int addmod(int a,int b){ a+=b; if(a>=MOD) a-=MOD; return a; }
int mulmod(int64 a,int64 b){ return int((a*b)%MOD); }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    vector<int> ds(T);
    int maxd=0;
    for(int i=0;i<T;i++){ cin>>ds[i]; maxd = max(maxd, ds[i]); }

    vector<int> ans(maxd+1,0);

    const int choice_after_first[3] = {4,3,3};
    const int choice_first[3] = {3,3,3}; 
    vector<int> cur(3*27, 0), nxt(3*27, 0);
    int idx0 = enc(1%3, 0, 0);
    cur[0*27 + idx0] = 1; 
    for(int pos=1; pos<=maxd; ++pos){
        fill(nxt.begin(), nxt.end(), 0);
        bool isFirst = (pos==1);
        for(int p=0;p<3;++p){
            for(int encIdx=0; encIdx<27; ++encIdx){
                int ways = cur[p*27 + encIdx];
                if(!ways) continue;
                int a,b,c; dec(encIdx, a,b,c);
                for(int r=0;r<3;++r){
                    int choices = isFirst ? choice_first[r] : choice_after_first[r];
                    if(choices==0) continue;
                    int np = (p + r) % 3;
                    int na=a, nb=b, nc=c;
                    if(np==0) na = (na+1)%3;
                    else if(np==1) nb = (nb+1)%3;
                    else nc = (nc+1)%3;
                    int nenc = enc(na,nb,nc);
                    int &cell = nxt[np*27 + nenc];
                    cell = (cell + (int64)ways * choices) % MOD;
                }
            }
        }
        cur.swap(nxt);
        int total = 0;
        for(int p=0;p<3;++p){
            for(int encIdx=0; encIdx<27; ++encIdx){
                int ways = cur[p*27 + encIdx];
                if(!ways) continue;
                int a,b,c; dec(encIdx,a,b,c);
                int cnt2 = (a==2) + (b==2) + (c==2);
                if(cnt2 % 3 == 0){
                    total = (total + ways) % MOD;
                }
            }
        }
        ans[pos] = total;
    }

    for(int i=0;i<T;++i){
        cout << ans[ ds[i] ] << '\n';
    }
    return 0;
}
