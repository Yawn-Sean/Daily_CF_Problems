#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> mmp(n);
    for (int i = 0; i < n - 1; i ++) {
        int sp, ep, v; cin >> sp >> ep >> v;
        sp --; ep --;
        mmp[sp].emplace_back(ep, v);
        mmp[ep].emplace_back(sp, v);
    }

    vector<int> group(n, -1);
    vector<int> pt_val(n, -1);
    
    function<void(int, int, int)> df_group;
    df_group = [&](int cur, int v, int gpn){
        group[cur] = gpn;
        pt_val[cur] = v;
        for (auto [nxp, edgv] : mmp[cur]) {
            if (group[nxp] != -1 || edgv == -1) continue;
            df_group(nxp, v ^ edgv, gpn);
        }
    };

    for (int i = 0; i < n; i++) {
        if (group[i] == -1) {
            df_group(i, 0, i);
        }
    }

    
    vector<vector<pair<int, int>>> req(n);
    for (int i = 0; i < m; i ++) {
        int a, b, p; cin >> a >> b >> p;
        a --; b --;
        int fcnt = (__builtin_popcount(pt_val[a] ^ pt_val[b] ^ p) & 1);
        req[group[a]].emplace_back(group[b], fcnt);
        req[group[b]].emplace_back(group[a], fcnt);
    }

    vector<int> g_flip(n, -1);
    bool bad = false;

    function<bool(int, int)> df_mark_check;
    df_mark_check = [&](int gid, int needv){
        if (g_flip[gid] == -1) {
            g_flip[gid] = needv;
            bool ok = true; 
            for (auto [nxgid, eflp] : req[gid]) {
                ok = df_mark_check(nxgid, eflp ^ needv);
                if (!ok) break;
            }
            return ok;
        } else {
            return g_flip[gid] == needv;
        }
    };

    for (int i = 0; i < n; i++) {
        if (g_flip[i] != -1) continue;
        bad = !df_mark_check(i, 0);
        if (bad) {
            break;
        } 
    }

    if (bad) {
        cout << "NO\n" ;
    } else {
        cout << "YES\n";
        for (int sp = 0; sp < n; sp++) {
            for (auto [ep, v] : mmp[sp]) {
                if (ep < sp) continue;
                if (v == -1) {
                    v = (pt_val[sp] ^ pt_val[ep] ^ g_flip[group[sp]] ^ g_flip[group[ep]] );
                } 
                cout << sp + 1 << " " << ep + 1 << " " << v << "\n";
            }
        }
    }
}

int main(void) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("0.in", "r", stdin);

    int T{1};
    cin >> T;
    
    while (T--) {
        solve();
    }

}