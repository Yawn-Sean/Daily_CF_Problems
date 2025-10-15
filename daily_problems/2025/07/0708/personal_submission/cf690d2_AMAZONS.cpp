#include<bits/stdc++.h>
using namespace std;
const int N =1e6 + 10;
const int mod=1e6+3;
#define int long long
//Lucas模板
int qpow(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

// 预处理阶乘和逆元数组
vector<int> fact, inv_fact;
void preprocess(int n, int p) {
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % p;
    inv_fact[n] = qpow(fact[n], p - 2, p);
    for (int i = n - 1; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % p;
}

int comb_small(int n, int m, int p) {
    if (m > n) return 0;
    return fact[n] * inv_fact[m] % p * inv_fact[n - m] % p;
}

// Lucas定理计算 C(n, m) mod p
int lucas(int n, int m, int p) {
    if (m == 0) return 1;
    int a = n % p, b = m % p;
    return comb_small(a, b, p) * lucas(n / p, m / p, p) % p;
}
void solve(){
	int n,l;cin>>n>>l;   
    if (fact.empty()) {
        preprocess(mod - 1, mod);
    }   
    cout<<(lucas(n+l,l,mod)-1+mod)%mod;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}