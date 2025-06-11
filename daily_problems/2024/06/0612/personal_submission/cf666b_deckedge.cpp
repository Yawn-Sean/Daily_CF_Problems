#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), m = red();
    ve<ve<int>> g(n), re_g(n);

    rep(i, 0, m) {
        int u = red(), v = red();
        u --, v --;
        g[u].emplace_back(v);
        re_g[v].emplace_back(u);
    }

    ve<ve<pi>> a3(3, ve<pi>(n, mk(-1, 1)));
    ve<ve<pi>> b3(3, ve<pi>(n, mk(-1, 1)));
    ve<ve<int>> dist(n, ve<int>(n, -1));

    ve<int> q;
    int hh;
    rep(i, 0, n) {
        ve<int> re_d(n, -1);
        q.clear();
        dist[i][i] = 0;
        q.emplace_back(i);
        hh = 0;
        
        while (hh < q.size()) {
            int u = q[hh++];
            for (auto &v: g[u]) {
                if (dist[i][v] == -1) {
                    dist[i][v] = dist[i][u] + 1;
                    q.emplace_back(v);
                }
            }
        }

        q.clear();
        re_d[i] = 0;
        q.emplace_back(i);
        hh = 0;
        
        while (hh < q.size()) {
            int u = q[hh++];
            for (auto &v: re_g[u]) {
                if (re_d[v] == -1) {
                    re_d[v] = re_d[u] + 1;
                    q.emplace_back(v);
                }
            }
        }

        rep(j, 0, n) {
            if (dist[i][j] > 0) {
                if (a3[0][i].second <= dist[i][j]) {
                    swap(a3[1][i], a3[2][i]);
                    swap(a3[0][i], a3[1][i]);
                    a3[0][i] = mk(j, dist[i][j]);
                }
                else if (a3[1][i].second <= dist[i][j]) {
                    swap(a3[1][i], a3[2][i]);
                    a3[1][i] = mk(j, dist[i][j]);
                }
                else if (a3[2][i].second < dist[i][j]) {
                    a3[2][i] = mk(j, dist[i][j]);
                }
            }
            if (re_d[j] > 0) {
                if (b3[0][i].second <= re_d[j]) {
                    swap(b3[1][i], b3[2][i]);
                    swap(b3[0][i], b3[1][i]);
                    b3[0][i] = mk(j, re_d[j]);
                }
                else if (b3[1][i].second <= re_d[j]) {
                    swap(b3[1][i], b3[2][i]);
                    b3[1][i] = mk(j, re_d[j]);
                }
                else if (b3[2][i].second < re_d[j]) {
                    b3[2][i] = mk(j, re_d[j]);
                }
            }
        }
    }

    int mx = 0;
    ve<int> res(4);
    rep(b, 0, n) {
        rep(c, 0, n) {
            if (dist[b][c] > 0) {
                rep(i, 0, 3) {
                    int a = b3[i][b].first;
                    if (a != -1 && a != c) {
                        rep(j, 0, 3) {
                            int d = a3[j][c].first;
                            if (d != -1 && d != a && d != b && dist[a][b] + dist[b][c] + dist[c][d] > mx) {
                                mx = dist[a][b] + dist[b][c] + dist[c][d], res[0] = a, res[1] = b, res[2] = c, res[3] = d;
                            } 
                        }
                    }
                }
            }
        }
    }
    rep(i, 0, 4) {
        cout << res[i] + 1 << " \n"[i == 3];
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}