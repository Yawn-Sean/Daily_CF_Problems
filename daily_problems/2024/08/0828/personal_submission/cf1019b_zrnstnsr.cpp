#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    if (n % 4 == 2) { cout << "! -1" << endl; return; }
    vector<int> res(n+1);
    cout << "? 1" << endl;
    cin >> res[0];
    cout << "? " << n / 2 + 1 << endl;
    cin >> res[n/2];
    if (res[0] == res[n/2]) { cout << "! 1" << endl; return; }
    cout << "? " << n / 4 + 1 << endl;
    cin >> res[n/4];
    cout << "? " << n / 4 * 3 + 1 << endl;
    cin >> res[3*n/4];
    if (res[n/4] == res[3*n/4]) { cout << "! " << n / 4 + 1 << endl; return; }
    int l, r;
    if ((res[0] - res[n/2]) * (res[n/4] - res[3*n/4]) < 0) l = 0, r = n / 4;
    else l = n / 4, r = n / 2;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        cout << "? " << m + 1 << endl;
        cin >> res[m];
        cout << "? " << m + n / 2 + 1 << endl;
        cin >> res[m+n/2];
        if (res[m] == res[m+n/2]) { cout << "! " << m + 1 << endl; return; }
        else if ((res[l] - res[l+n/2]) * (res[m] - res[m+n/2]) < 0) r = m;
        else l = m;
    }
    cout << "! -1" << endl;
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
