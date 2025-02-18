#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1E9 + 7;
const int N = 5000000;
int pr[N / 5], p[N + 100], tot;
ll f[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, l, r;
    cin >> t >> l >> r;
    for (int i = 2; i <= r; i++) {
        if (!p[i]) p[i] = i, pr[++tot] = i;
        for (int j = 1; j <= tot && pr[j] * i <= r; j++) {
            p[i * pr[j]] = pr[j];
            if (p[i] == pr[j]) break;
        }
    }

    for (int i = 2; i <= r; i++) {
        if (p[i] == i) f[i] = (ll)i * (i - 1) / 2;
        else f[i] = f[p[i]] * (i / p[i]) + f[i / p[i]];
        f[i] = f[i] % mod;
    }

    ll ans = 0;
    for (int i = r; i >= l; i--)
        ans = (ans * t + f[i]) % mod;

    cout << ans << '\n';
    return 0;
}