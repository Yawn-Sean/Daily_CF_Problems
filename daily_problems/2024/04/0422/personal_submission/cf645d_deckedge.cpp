#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pi pair<int, int>
#define all(x) (x).begin(), (x).end()

inline int red() {
    int x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = red(), m = red(), i;
    vector<int> a(m), b(m), in(n);
    vector<vector<int>> g(n);

    for (i = 0; i < m; ++i) {
        int aa = red(), bb = red();
        --aa, --bb;
        a[i] = aa;
        b[i] = bb;
    }

    auto check = [&](int mid) {
        int i;
        in.assign(n, 0);
        for (i = 0; i < n; i++) {
            g[i].clear();
        }
        for (i = 1; i <= mid; i++) {
            g[a[i - 1]].emplace_back(b[i - 1]);
            in[b[i - 1]]++;
        }
        queue<int> q;
        for (i = 0; i < n; i++) {
            if (!in[i]) {
                q.emplace(i);
            }
        }   

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            if (!q.empty()) {
                return false;
            }
            for (i = 0; i < g[t].size(); i++) {
                int u = g[t][i];
                in[u]--;
                if (!in[u]) {
                    q.push(u);
                }
            }
        }

        return true;
    };

    int l = 1, r = m, res = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << res << '\n';


    return 0;
}

