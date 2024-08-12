#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long d, mod;
    cin >> d >> mod;

    long long cnt = 1;
    for(long long i=1; i<=d; i*=2) {
        cnt *= min(i*2-1, d) - i + 1 + 1;
        cnt %= mod;
    }

    cnt = (cnt + mod - 1) % mod;
    cout << cnt << endl;
}
