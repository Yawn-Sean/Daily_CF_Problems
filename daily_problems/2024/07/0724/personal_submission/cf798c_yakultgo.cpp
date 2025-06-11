#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int g = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = gcd(g, a[i]);
    }
    int ans = 0;
    if (g == 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) continue;
            int j = i;
            while (j < n && a[j] % 2 == 1) j++;
            ans += (j - i) / 2;
            if ((j - i) % 2 == 1) {
                ans += 2;
            }
            i = j;
        }
    }
    cout << "YES" << endl;
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