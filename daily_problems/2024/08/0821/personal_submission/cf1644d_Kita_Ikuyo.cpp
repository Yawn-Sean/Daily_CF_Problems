c#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

# ifdef LOCAL

# include "C:\Users\yangbo\Desktop\untitled1\template\debug.h"

# else
# define debug(...) 114514
# define ps 114514
# endif
const long long mod = 998244353;
int row[200005], col[200005];
pair<int,int> v[200005];
void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    long long ans = 1;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 1; i <= max(n, m); i++)row[i] = col[i] = 0;

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        v[i] = {l,r};
    }

    for (int i = q; i >= 1; i--) {
        int x = v[i].first;
        int y = v[i].second;
        int c = 1;
        if (cnt1 == n || cnt2 == m)break;
        if (!row[x]) {
            cnt1++;
            row[x] = 1;
            c = k;
        }
        if (!col[y]) {
            cnt2++;
            col[y] = 1;
            c = k;
        }
        //debug(c);
        ans *= c;
        ans %= mod;
    }

    cout << ans << '\n';
}

signed main() {
    IOS
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}
