#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const ll inf = 2e18;
using i128 = __int128;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 1)
            arr.push_back(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        i128 mul = a[i];
        ll sum = 1ll * a[i] * k;
        int cur = i;
        while (true) {
            if (mul == sum) ans++;
            auto it = upper_bound(arr.begin(), arr.end(), cur);
            int pos;
            ll tmp = (mul - sum) % k;
            ll cnt = (mul - sum) / k;
            if (it == arr.end()) {
                pos = n;
            } else {
                pos = *it;
            }
            if (tmp == 0 && cnt < (pos - cur) && mul > sum)
                ans++;
            if (it == arr.end()) break;
            mul *= a[pos];
            if (mul > inf) break;
            sum += 1ll * (pos - cur - 1) * k + 1ll * a[pos] * k;
            cur = pos;
        }
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