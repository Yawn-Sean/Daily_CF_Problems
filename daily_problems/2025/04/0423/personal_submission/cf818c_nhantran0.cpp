/**
 * https://codeforces.com/problemset/problem/818/C
 * C. Sofa Thief
 * Solver: nhant
 * 2025-04-24 00:32:39
 * https://codeforces.com/problemset/submission/818/316862374
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int d, n, m, reqcntl, reqcntr, reqcntt, reqcntb;
    cin >> d >> n >> m;
    vector<vector<int>> p(d, vector<int>(4));
    vector<int> cl(n + 2), cr(n + 2), ct(m + 2), cb(m + 2);
    for (int i = 0; i < d; i++) {
        cin >> p[i][0] >> p[i][1] >> p[i][2] >> p[i][3];
        cl[min(p[i][0], p[i][2])]++;
        cr[max(p[i][0], p[i][2])]++;
        ct[min(p[i][1], p[i][3])]++;
        cb[max(p[i][1], p[i][3])]++;
    }
    for (int x = 1; x <= n; x++) {
        cl[x] += cl[x - 1];
        cr[n + 1 - x] += cr[n + 2 - x];
    }
    for (int y = 1; y <= m; y++) {
        ct[y] += ct[y - 1];
        cb[m + 1 - y] += cb[m + 2 - y];
    }
    cin >> reqcntl >> reqcntr >> reqcntt >> reqcntb;
    int res = 0;
    for (int i = 0; i < d; i++) {
        int xl = min(p[i][0], p[i][2]), xr = max(p[i][0], p[i][2]);
        int yt = min(p[i][1], p[i][3]), yb = max(p[i][1], p[i][3]);
        int cntl = cl[xr - 1] - (xl < xr);
        int cntr = cr[xl + 1] - (xl < xr);
        int cntt = ct[yb - 1] - (yt < yb);
        int cntb = cb[yt + 1] - (yt < yb);
        if (cntl == reqcntl && cntr == reqcntr && cntt == reqcntt && cntb == reqcntb) {
            res = i + 1;
            break;
        }
    }
    cout << (res == 0 ? -1 : res) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
