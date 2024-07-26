#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n < 1ll * (k + 1) * k / 2) {
        cout << "NO" << endl;
        return;
    }
    n -= 1ll * (k + 1) * k / 2;
    vector<int> a(k + 1);
    iota(a.begin(), a.end(), 0);
    a[0] = 1e9;
    int add = 0;
    for (int i = 1; i <= k; i++) {
        a[i] += add;
        int x = min(2 * a[i - 1] - a[i], n / (k - i + 1));
        a[i] += x;
        add += x;
        n -= x * (k - i + 1);
    }
    if (n != 0) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 2; i <= k; i++) {
        if (a[i] <= 2 * a[i - 1] && a[i] > a[i - 1]) continue;
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
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