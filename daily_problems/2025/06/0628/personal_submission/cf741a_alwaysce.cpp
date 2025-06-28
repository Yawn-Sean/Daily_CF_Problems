#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    vector<int> cycs;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            int cur = i;
            int cnt = 0;
            while (!vis[cur]) {
                vis[cur] = 1;
                cur = p[cur];
                cnt++;
            }
            if (cur != i) {
                cout << -1 << endl;
                return 0;
            }
            cycs.push_back(cnt);
        }
    }

    int l = 1;
    for (int cyc : cycs) {
        l = lcm(l, (cyc % 2 == 0) ? cyc / 2 : cyc);
    }
    cout << l << endl;
    return 0;
}
