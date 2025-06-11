#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n), rev_g(n);

    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        g[u].push_back(v);
        rev_g[v].push_back(u);
    }

    vector<vector<pair<int, int>>> large3(3, vector<pair<int, int>>(n, make_pair(-1, 1)));
    vector<vector<pair<int, int>>> rev_large3(3, vector<pair<int, int>>(n, make_pair(-1, 1)));
    vector<vector<int>> dist(n, vector<int>(n, -1));

    vector<int> q;
    int l;
    for (int i = 0; i < n; i ++) {
        vector<int> revdist(n, -1);

        q.clear();
        dist[i][i] = 0;
        q.push_back(i);
        l = 0;
        
        while (l < q.size()) {
            int u = q[l];
            l ++;
            for (auto &v: g[u]) {
                if (dist[i][v] == -1) {
                    dist[i][v] = dist[i][u] + 1;
                    q.push_back(v);
                }
            }
        }

        q.clear();
        revdist[i] = 0;
        q.push_back(i);
        l = 0;
        
        while (l < q.size()) {
            int u = q[l];
            l ++;
            for (auto &v: rev_g[u]) {
                if (revdist[v] == -1) {
                    revdist[v] = revdist[u] + 1;
                    q.push_back(v);
                }
            }
        }

        for (int j = 0; j < n; j ++) {
            if (dist[i][j] > 0) {
                if (large3[0][i].second <= dist[i][j]) {
                    swap(large3[1][i], large3[2][i]);
                    swap(large3[0][i], large3[1][i]);
                    large3[0][i] = make_pair(j, dist[i][j]);
                }
                else if (large3[1][i].second <= dist[i][j]) {
                    swap(large3[1][i], large3[2][i]);
                    large3[1][i] = make_pair(j, dist[i][j]);
                }
                else if (large3[2][i].second < dist[i][j]) {
                    large3[2][i] = make_pair(j, dist[i][j]);
                }
            }
            if (revdist[j] > 0) {
                if (rev_large3[0][i].second <= revdist[j]) {
                    swap(rev_large3[1][i], rev_large3[2][i]);
                    swap(rev_large3[0][i], rev_large3[1][i]);
                    rev_large3[0][i] = make_pair(j, revdist[j]);
                }
                else if (rev_large3[1][i].second <= revdist[j]) {
                    swap(rev_large3[1][i], rev_large3[2][i]);
                    rev_large3[1][i] = make_pair(j, revdist[j]);
                }
                else if (rev_large3[2][i].second < revdist[j]) {
                    rev_large3[2][i] = make_pair(j, revdist[j]);
                }
            }
        }
    }

    int ans = 0;
    vector<int> outs(4);
    for (int b = 0; b < n; b ++)
        for (int c = 0; c < n; c ++) {
            if (dist[b][c] > 0) {
                for (int i = 0; i < 3; i ++) {
                    int a = rev_large3[i][b].first;
                    if (a != -1 && a != c) {
                        for (int j = 0; j < 3; j ++) {
                            int d = large3[j][c].first;
                            if (d != -1 && d != a && d != b && dist[a][b] + dist[b][c] + dist[c][d] > ans) {
                                ans = dist[a][b] + dist[b][c] + dist[c][d], outs[0] = a, outs[1] = b, outs[2] = c, outs[3] = d;
                            } 
                        }
                    }
                }
            }
        }

    for (auto &x: outs) cout << x + 1 << ' ';
    return 0;
}