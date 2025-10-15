#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n;
    cin >> n;
    vector <int> p(n+1), vis(n+1);
    for (int i = 1; i <= n; ++ i) cin >> p[i];

    auto dfs_merge = [&](auto &&self, int u, int color)->int{
        vis[u] = color;
        int x = p[u], y = u;
        if (vis[x] == vis[y]){
            return x;
        } else {
            if (vis[x]) return -1;
            return self(self, p[u], color);
        }
    };

    set <int> st;
    for (int i = 1, tot = 0; i <= n; ++ i){
        if (vis[i]) continue;
        int rt = dfs_merge(dfs_merge, i, ++ tot);
        if (rt == -1) continue;
        st.insert(rt);
    }

    int rt = -1;
    for (auto &x : st){
        if (p[x] == x){
            rt = x;
        }
    }

    vector <int> rts;
    for (auto &x : st){
        if (x == rt) continue;
        rts.push_back(x);
    }
    if (rt != -1) rts.push_back(rt);

    int len = rts.size();
    // cout << len << "\n";
    // return;
    vector <int> ans = p;

    for (int i = 0; i < len-1; ++ i){
        int x = rts[i], y = rts[i+1];
        ans[x] = y;
    }
    if (rt == -1){
        int r = rts[len-1];
        assert(p[r] != r);
        ans[r] = r;
    }

    int res = len-1 + (rt == -1);
    cout << res << "\n";
    for (int i = 1; i <= n; ++ i){
        if (i > 1) cout << " ";
        cout << ans[i];
    }
    cout << "\n";

}
