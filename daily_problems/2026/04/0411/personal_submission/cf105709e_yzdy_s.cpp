#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 1e5 + 7;
vector<int> fa(maxN);
vector<int> siz(maxN);

int mx = 1;
int find(int x) {
    if (fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int u, int v) {
    int u_fa = find(u);
    int v_fa = find(v);
    if (u_fa == v_fa) return;
    if (siz[u_fa] < siz[v_fa]) {
        fa[u_fa] = v_fa;
        siz[v_fa] += siz[u_fa];
        siz[u_fa] = 0;
    } else {
        fa[v_fa] = u_fa;
        siz[u_fa] += siz[v_fa];
        siz[v_fa] = 0;
    }
    mx = max({mx, siz[u_fa], siz[v_fa]});
}

void solve(){
    int n, k, q;cin >> n >> k >> q;
    vector<string> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        string s;cin >> s;
        s = '#' + s;
        arr[i] = s;
    }
    mx = 1;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        siz[i] = 1;
    }

    vector<int> vis(k + 1);
    while (q--) {
        int op;cin >> op;
        if (op == 1) {
            int j;cin >> j;
            if (vis[j]) continue;
            vis[j] = 1;
            vector<int> t(20);
            for (int i = 1; i <= n; i++) {
                int idx = arr[i][j] - 'a';
                if (t[idx] == 0) t[idx] = i;
                else {
                    int u = i;
                    int v = t[idx];
                    merge(u, v);
                }
            }
        } else if (op == 2) {
            int i;cin >> i;
            int root = find(i);
            cout << siz[root] << endl;
        } else {
            cout << mx << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
