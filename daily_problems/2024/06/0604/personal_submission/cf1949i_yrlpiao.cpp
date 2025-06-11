#include <iostream>
#include <vector>
#include <array>
using namespace std;
#define ar3 array<int, 3>
#define int long long
vector<int> ed[1010];
int vis[1010] {};
bool check(auto x, auto y) {
    int x1 = x[0], y1 = x[1], r1 = x[2];
    int x2 = y[0], y2 = y[1], r2 = y[2];
    int a = x1 - x2, b = y1 - y2;
    return a * a + b * b == (r1 + r2) * (r1 + r2);
}
int dfs(int u, auto& p) {
    int ret = 1;
    for (int x : ed[u]) {
        if (vis[x] == 0) {
            vis[x] = 3 - vis[u]; 
            p[vis[x]]++;
            int t = dfs(x, p);
            if (t == 0) ret = t;
        } else if (vis[x] == vis[u]) {
            ret = 0;
        }
    }
    return ret;
}
void yrlpSolve() {
    int n; cin >> n;
    vector<ar3> a(n);
    for (auto& x : a) cin >> x[0] >> x[1] >> x[2];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (check(a[i], a[j])) {
                ed[i].push_back(j);
                ed[j].push_back(i);
            }
        }
    }
    int flg = 0;
    for (int i = 0; i < n; i ++)
        if (vis[i] == 0) {
            ar3 p = {0, 1, 0}; vis[i] = 1;
            if (dfs(i, p) && (p[1] != p[2])) {
                flg = 1;
                break;
            }
        }
    cout << (flg ? "YES" : "NO") << '\n';
    return; 
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
