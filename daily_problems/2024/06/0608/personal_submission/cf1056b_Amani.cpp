#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    ll a[m];
    for (int i = 0; i < m; ++i) {
        a[i] = n / m;
    }
    for (int i = (n / m) * m + 1; i <= n; ++i) {
        a[i % m]++;
    }
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!((i*i + j*j) % m)) {
                ans += a[i] * a[j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*  Another method:
    long long ans = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!((i*i + j*j) % m)) {
                ans += 1LL * ((n+m-i)/m) * ((n+m-j)/m);
            }
        }
    }
    return ans;
 */