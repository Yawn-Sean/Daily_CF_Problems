#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

int a[5050], cnt[5050];
int mod = 998'244'353;

void yrlpSolve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cnt[0] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 5000 - a[i]; j >= 0; j--) {
            cnt[j + a[i]] += cnt[j]; cnt[j + a[i]] %= mod;
            if (j <= a[i]) ans += a[i] * cnt[j] % mod;
            else {
                ans += ((j + a[i]) / 2 + ((j + a[i]) & 1)) * cnt[j] % mod;
            }
            ans %= mod;
        }
    }
    cout << ans;
    return; 
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
