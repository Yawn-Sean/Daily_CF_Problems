#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD1 = 1000000007LL;
const int64 MOD2 = 1000000009LL;
int64 modpow(int64 a,int64 e,int64 mod){int64 r=1%mod;while(e){if(e&1)r=(__int128)r*a%mod;a=(__int128)a*a%mod;e>>=1;}return r;}
int64 invmod(int64 a,int64 mod){return modpow((a%mod+mod)%mod,mod-2,mod);}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    if(!(cin>>q))return 0;
    vector<int64> s1,s2;
    vector<int> opToIdx(q+1,-1);
    int64 mul1=1,add1=0,mul2=1,add2=0;
    for(int i=1;i<=q;i++){
        int t;
        cin>>t;
        if(t==1){
            int64 x;cin>>x;
            int idx = s1.size();
            int64 val1 = ( (x%MOD1 - add1)%MOD1 + MOD1 )%MOD1;
            val1 = ( (__int128)val1 * invmod(mul1,MOD1) )%MOD1;
            int64 val2 = ( (x%MOD2 - add2)%MOD2 + MOD2 )%MOD2;
            val2 = ( (__int128)val2 * invmod(mul2,MOD2) )%MOD2;
            s1.push_back(val1);
            s2.push_back(val2);
            opToIdx[i]=idx;
        } else if(t==2){
            int64 x;cin>>x;
            add1 = (add1 + x) % MOD1; if(add1<0) add1+=MOD1;
            add2 = (add2 + x) % MOD2; if(add2<0) add2+=MOD2;
        } else if(t==3){
            int64 p,qv;cin>>p>>qv;
            int64 invq1 = invmod(qv,MOD1);
            int64 invq2 = invmod(qv,MOD2);
            mul1 = (__int128)mul1 * p % MOD1 * invq1 % MOD1;
            add1 = (__int128)add1 * p % MOD1 * invq1 % MOD1;
            mul2 = (__int128)mul2 * p % MOD2 * invq2 % MOD2;
            add2 = (__int128)add2 * p % MOD2 * invq2 % MOD2;
        } else if(t==4){
            int j;cin>>j;
            int idx = opToIdx[j];
            int64 a1 = ( (__int128)mul1 * s1[idx] + add1 ) % MOD1;
            int64 a2 = ( (__int128)mul2 * s2[idx] + add2 ) % MOD2;
            int64 m1 = MOD1, m2 = MOD2;
            int64 inv_m1_mod_m2 = invmod(m1 % m2, m2);
            int64 diff = (a2 - a1) % m2; if(diff<0) diff+=m2;
            int64 k = (__int128)diff * inv_m1_mod_m2 % m2;
            __int128 x = (__int128)a1 + (__int128)m1 * k;
            long long ans = (long long)x;
            cout<<ans<<"\n";
        }
    }
    return 0;
}
