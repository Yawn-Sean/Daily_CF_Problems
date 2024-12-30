#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define mn 1111111
int l = -1, s, p, q, a[mn];
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            if (p) a[++q] = i - p - 1;
            l = p = i;
            s += 2;
            k--;
        }
    }
    if (k < 0) {
        cout << -1 << endl;
        return;
    }
    sort(a + 1, a + 1 + q);
    for (int i = 1; i <= q; i++)
        if (k >= a[i])
            k -= a[i], s -= 2;
        else
            break;
    cout << (n - l <= k ? s - 1 : s) << endl;
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