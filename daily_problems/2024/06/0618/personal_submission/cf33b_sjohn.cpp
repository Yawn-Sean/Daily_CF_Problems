#include <bits/stdc++.h>

using namespace std;


using i64 = long long;
using pii = pair<int, int>;
//using u32 = unsigned;
constexpr int inf = 1e6;
//constexpr i64 inf = INT64_MAX >> 1;
using vi = vector<int>;
using vl = vector<i64>;
using vb = vector<bool>;
#define all(x) (x).begin(),(x).end()


int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size()) {
        cout << -1 << endl;
        return 0;
    }
    int n = a.size();
    vector g(26, vi(26, inf));
    int t;
    cin >> t;
    while (t--) {
        char c1, c2;
        int v;
        cin >> c1 >> c2 >> v;
        c1 -= 'a';
        c2 -= 'a';
        g[c1][c2] = min(g[c1][c2], v);
    }
    for (int i = 0; i < 26; ++i) {
        g[i][i] = 0;
    }
    for (int k = 0; k < 26; ++k)
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
//                int tmp = g[i][k] + g[k][j];
//                if (tmp < inf) cout << i << ' ' << k << ' ' << j << endl;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    int cost = 0;
    string ans("#", n);
    for (int i = 0; i < n; ++i) {
        int x = a[i] - 'a', y = b[i] - 'a';
        if (a[i] == b[i]) ans[i] = a[i];
        else {
            int mi = inf, id = -1;
            for (int k = 0; k < 26; ++k)
                if (mi > g[x][k] + g[y][k]) {
                    id = k;
                    mi = g[x][k] + g[y][k];
                }
            if (id == -1) {
                cout << -1 << endl;
                return 0;
            } else ans[i] = id + 'a', cost += mi;
        }
    }
    cout << cost << endl;
    cout << ans << endl;
}






