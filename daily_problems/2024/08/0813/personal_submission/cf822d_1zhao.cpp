#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;

int qmi(int a, int k, int p)
{
    int res = 1 % p;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

void solve() {
    int t, l, r;
    cin >> t >> l >> r;
    vector<long long> f(r+1, 1e15);
    f[1] = 0;
    for(int i=1; i<=r; i++) {
        for(int j=2; j<=r/i; j++) {
            f[i*j] = min(f[i*j], f[i] + (LL)i * j * (j-1) / 2);
        }
    }
    long long res = 0;
    for(int i=l; i<=r; i++) {
        f[i] %= mod;
        res += f[i] * qmi(t, i-l, mod);
        res %= mod;
    }
    cout << res << endl;
}
