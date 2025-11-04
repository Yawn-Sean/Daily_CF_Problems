#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 M = 998244353;

int64 modpow(int64 a, int64 e){
    int64 r = 1 % M;
    while(e){
        if(e & 1) r = (r * a) % M;
        a = (a * a) % M;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if(!(cin >> T)) return 0;
    vector<int> qs(T);
    int maxN = 0;
    for(int i=0;i<T;i++){
        cin >> qs[i];
        if(qs[i] > maxN) maxN = qs[i];
    }
    if(maxN < 1) {
        for(int i=0;i<T;i++) cout << 0 << '\n';
        return 0;
    }
    // precompute factorials and invfactorials up to maxN
    vector<int64> fact(maxN+1), invfact(maxN+1);
    fact[0] = 1;
    for(int i=1;i<=maxN;i++) fact[i] = fact[i-1] * i % M;
    invfact[maxN] = modpow(fact[maxN], M-2); // Fermat inverse
    for(int i=maxN;i>0;i--) invfact[i-1] = invfact[i] * i % M;
    
    // prefix xor answers: pref[j] = XOR_{x=1..j} row_contribution(x)
    vector<int64> pref(maxN+1);
    pref[0] = 0;
    for(int j=1;j<=maxN;j++){
        int64 contrib;
        if(j & 1){
            contrib = 1; // odd rows
        } else {
            int half = j/2;
            // C(j, j/2) mod M = fact[j] * invfact[half] * invfact[half] % M
            int64 cent = fact[j];
            cent = cent * invfact[half] % M;
            cent = cent * invfact[half] % M;
            contrib = (cent ^ 1LL);
        }
        pref[j] = pref[j-1] ^ contrib;
    }
    
    for(int i=0;i<T;i++){
        cout << pref[qs[i]] << '\n';
    }
    return 0;
}
