#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PII;

LL h, q;
LL mi2[55];

LL getl(int x, int i) {
    return (LL)x * mi2[h - i];
}

LL getr(int x, int i) {
    return (LL)(x + 1) * mi2[h - i] - 1;
}

signed main() {
    cin >> h >> q;
    mi2[0] = 1;
    for (int i = 1; i <= 50; i++) mi2[i] = 2 * mi2[i - 1];
    LL tl = getl(1, 1), tr = getr(1, 1);
    int th, x1, x2, ans;
    LL ll, rr;
    vector<PII> v, v1;

    while (q--) {
        cin >> th >> x1 >> x2 >> ans;
        ll = getl(x1, th);
        rr = getr(x2, th);
        if (ans) {
            tl = max(tl, ll);
            tr = min(tr, rr);
            if (tl > tr) {
                cout << "Game cheated!";
                return 0;
            }
        } else {
            v.push_back({ll, rr});
        }
    }
    if (v.empty()) {
        if (tr - tl > 0) return cout << "Data not sufficient!\n", 0;
        return cout << tl << '\n', 0;
    }
    sort(v.begin(), v.end());
    LL cl = v.front().x, cr = v.front().y, lst = getl(1, 1);
    
    for (auto it = v.begin(); it != v.end(); ++it) {
        LL l = it->first;
        LL r = it->second;
        if (l <= cr) cr = max(cr, r);
        else {
            if (lst < cl) v1.push_back({lst, cl - 1});
            lst = cr + 1, cl = l, cr = r;
        }
    }
    
    if (lst < cl) v1.push_back({lst, cl - 1});
    LL R = getr(1, 1);
    if (cr < R) v1.push_back({cr + 1, R});
    
    ans=0;
    for (auto it = v1.begin(); it != v1.end(); ++it) {
        LL l = it->first;
        LL r = it->second;
        if (r < tl || l > tr) continue;
        int lp = max(l, tl), rp = min(r, tr);
        if (rp - lp > 0 || ans) return cout << "Data not sufficient!\n", 0;
        ans = lp;
    }
    
    if (ans == 0) cout << "Game cheated!";
    else cout << ans;
    
    return 0;
}
