#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    vector<int> cnt(10, 0);
    int cur = 0;

    for (int i = 0; i < n; i ++) {
        int ncur = s[i] - '0';
        if (i || ncur)
            cnt[(ncur - cur + 10) % 10] ++;
        cur = ncur;
    }

    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 10; j ++) {
            vector<int> dis(10, 10);

            dis[i] = 0, dis[j] = 0;
            queue<int> q;
            q.push(i), q.push(j);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                int nu;
                nu = (u + i) % 10;
                if (dis[nu] == 10) {
                    dis[nu] = dis[u] + 1;
                    q.push(nu);
                }

                nu = (u + j) % 10;
                if (dis[nu] == 10) {
                    dis[nu] = dis[u] + 1;
                    q.push(nu);
                }
            }

            int res = 0;
            bool flg = true;
            for (int x = 0; x < 10; x ++) {
                if (cnt[x] && dis[x] == 10) flg = false;
                res += cnt[x] * dis[x];
            }

            cout << (flg ? res : -1) << ' ';
        }
        cout << '\n';
    }

    return 0;
}