#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 20;
int n, k, p, x;
vector<int> a, b, ans;

void solve() {
    cin >> n >> k >> p;
    int q = k - p;
    a.clear();
    b.clear();
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x % 2 == 0) {
            a.push_back(x);
        }
        else {
            b.push_back(x);
        }
    }
    int cnt = a.size();
    int s = 0;
    for (s = 0; cnt < p && s + 2 <= b.size(); s += 2) {
        a.push_back(b[s]);
        a.push_back(b[s + 1]);
        cnt++;
    }
    int re = b.size() - s;
    if (cnt < p || re < q) {
        cout << "NO" << endl;
    } else if ((re - q + 1) % 2 == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int j = 0;
        for (int i = 1; i <= p - 1; i++) {
            if (a[j] % 2) {
                cout << 2 << ' ' << a[j++] << ' ' << a[j++] << endl;
            } else {
                cout << 1 << ' ' << a[j++] << endl;
            }
        }
        if (p) {
            int x = 0;
            if (q == 0) {
                x = re;
            }
            cout << a.size() - j + x;
            while (x) {
                cout << ' ' << b[s++], x--;
            }
            for (; j < a.size(); j++) {
                cout << ' ' << a[j];
            }
            cout << endl;
        }
        for (int i = 1; i <= k - p - 1; i++) {
            cout << 1 << ' ' << b[s++] << endl;
        }
        if (k - p) {
            int x = 0;
            if (j < a.size()) {
                x = a.size() - j;
            }
            cout << b.size() - s + x;
            while (j < a.size()) {
                cout << ' ' << a[j++];
            }
            for (; s < b.size(); s++) {
                cout << ' ' << b[s];
            }
            cout << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
