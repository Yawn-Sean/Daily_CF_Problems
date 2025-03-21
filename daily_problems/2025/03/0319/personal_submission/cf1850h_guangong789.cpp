#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 2e5+10;
int a[MAXN], b[MAXN], d[MAXN], par[MAXN], wt[MAXN];

void init(int n) {
    memset(wt, 0, sizeof(wt));
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
    }
}

int find(int i) {
    if (par[i] != i) {
        int root = find(par[i]);
        wt[i] += wt[par[i]];
        par[i] = root;
    }
    return par[i];
}

void solve() {
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i] >> d[i];
    }
    for (int i = 1; i <= m; ++i) {
        int ai = a[i], bi = b[i];
        int par_a = find(ai), par_b = find(bi);
        if (par_a == par_b) {
            if (wt[ai] - wt[bi] != d[i]) {
                cout << "NO\n";
                return;
            }
        } else {
            par[par_a] = par_b;
            wt[par_a] = d[i] + wt[bi] - wt[ai];
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}