#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long

#ifdef LOCAL
#include "C:\Program Files\DEBUG\debug.h"
#else
#define debug(...) 114514
#define ps 114514
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    bool f = 1;
    int j = n;
    vector<int> cnt(n + 1);
    for (int i = n; i >= 1 && j >= 1; i--) {
        if (j > 0 && b[j] == a[i]) {
            j--;
        } else if (j < n && b[j] == b[j + 1]) {
            cnt[b[j]]++;
            j--;
            i++;
        } else if (cnt[a[i]]) {
            cnt[a[i]]--;
        } else {
            f = 0;
        }
    }
    cout << (f ? "YES" : "NO") << endl;
}

signed main() {
    IOS int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
