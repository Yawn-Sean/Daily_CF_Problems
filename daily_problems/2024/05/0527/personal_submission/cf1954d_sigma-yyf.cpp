#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    int s = accumulate(a.begin(), a.end() , 0);
    vector<int> f(s + 1);
    f[0] = 1;
    int ans = 0;
    for (int i = 0, cu = 0; i < n; i += 1, cu += a[i]) {
        for (int j = 0; j <= cu; ++j) {
            if (j <= a[i]) ans = (ans + f[j] * 1ll * a[i]) % mod;
            else {
                ans = (ans + (j + a[i] + 1) / 2 * 1ll * f[j]) % mod;
            }
        }
        for (int j = s; j >= a[i]; --j) {
            f[j] = (f[j] + f[j - a[i]]) % mod;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
