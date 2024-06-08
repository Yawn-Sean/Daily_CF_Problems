#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, d;
    cin >> n >> m >> d;

    vector<int> u(m), v(m), to1;
    for (int i = 0; i < m; i ++) {
        cin >> u[i] >> v[i], u[i] --, v[i] --;
        if (u[i] == 0 || v[i] == 0)
            to1.push_back(i);
    }

    if (to1.size() < d) {
        cout << "NO\n";
        return 0;
    }

    dsu dsu1(n), dsu2(n);

    for (int i = 0; i < m; i ++) 
        if (u[i] != 0 && v[i] != 0)
            dsu1.merge(u[i], v[i]);

    int cnt = 0, k = to1.size();
    vector<int> components(n), used(k);

    for (int i = 0; i < m; i ++) {
        int x = dsu1.leader(u[i] ? u[i] : v[i]);
        cnt -= components[x];
        components[x] = 1;
        cnt += components[x];
    }

    if (d < cnt) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    for (int i = 0; i < k; i ++) {
        int x = u[to1[i]] ? u[to1[i]] : v[to1[i]];
        if (components[dsu1.leader(x)]) {
            components[dsu1.leader(x)] = 0;
            used[i] = 1;
            d --;
            dsu2.merge(x, 0);
            cout << 1 << ' ' << x + 1 << '\n';
        }
    }

    for (int i = 0; i < k; i ++) {
        int x = u[to1[i]] ? u[to1[i]] : v[to1[i]];
        if (used[i] == 0 && d > 0) {
            d --;
            dsu2.merge(x, 0);
            cout << 1 << ' ' << x + 1 << '\n';
        }
    }

    for (int i = 0; i < m; i ++) 
        if (u[i] != 0 && v[i] != 0 && dsu2.merge(u[i], v[i]))
            cout << u[i] + 1 << ' ' << v[i] + 1 << '\n';
    return 0;
}