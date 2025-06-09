#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

i64 qpow(i64 a, i64 b) {
    a %= mod;
    i64 ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a;
    cin >> a;
    int k;
    cin >> k;
    /*
        2^i + 2^(i+k)+ ... + 2^(i + mk)
        = 2^i (2^0 + 2^k + ... + 2^(mk))

        q = 2^k
        2^i * ((1 - q^m) / (1 - q))

    */
    int n = a.size();
    i64 ans = 0;
    i64 q = qpow(2, n);

    i64 add = (qpow(q, k) - 1ll + mod) % mod;
    add = add * qpow(q - 1, mod - 2) % mod;

    for (int i = 0; i < n; i++) {
        if (a[i] == '0' || a[i] == '5') {            
            ans = (ans + qpow(2, i)) % mod;
        }
    }
    cout << ans * add % mod << endl;
    return 0;
}
