#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    ll n, b;
    cin >> n >> b;
    // 把b质因数分解了
    map<ll, int> mp;
    for (int i = 2; 1ll * i * i <= b; i++) {
        if (b % i == 0) {
            int cnt = 0;
            while (b % i == 0) {
                b /= i;
                cnt++;
            }
            mp[i] = cnt;
        }
    }
    if (b > 1) mp[b] = 1;
    // 枚举1～n中的每个数，看看有多少b的质因子
    map<ll, ll> cnt;
    for (auto [k, _] : mp) {
        ll t = n;
        while (t) {
            cnt[k] += t / k;
            t /= k;
        }
    }
    ll ans = 1e18;
    for (auto [k, v] : mp) {
        ans = min(ans, cnt[k] / v);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}