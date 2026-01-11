#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int tot = 1 << m;

    vector<int> vals(tot, -100);
    vector<int> idxs(tot, 0);
    vector<int> msks(n);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        int msk = 0;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'Y')
                msk |= (1 << j);
        }

        msks[i] = msk;

        if (vals[msk] < 0) {
            vals[msk] = 0;
            idxs[msk] = i;
        }
    }

    // if vals[-1] == 0 in Python -> full mask = (1<<m)-1
    int full = (1 << m) - 1;

    if (vals[full] == 0) {
        int chosen = -1;

        for (int i = 0; i < n; ++i) {
            if (i != idxs[full]) {
                if (chosen == -1 || __builtin_popcount(msks[chosen]) < __builtin_popcount(msks[i])) {
                    chosen = i;
                }
            }
        }

        int x = chosen;
        int y = idxs[full];
        if (x > y) swap(x, y);

        cout << x + 1 << " " << y + 1 << '\n';
    } else {
        // subset DP (same as python double loop)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < (1 << m); ++j) {
                if ((j >> i) & 1) {
                    int nj = j ^ (1 << i);
                    if (vals[j] + 1 > vals[nj] || 
                        (vals[j] + 1 == vals[nj] && idxs[j] < idxs[nj])) {
                        vals[nj] = vals[j] + 1;
                        idxs[nj] = idxs[j];
                    }
                }
            }
        }

        int cur = -1;
        int x = -1, y = -1;

        for (int i = 0; i < n; ++i) {
            int v = ((1 << m) - 1) - msks[i];
            if (vals[v] > cur) {
                cur = vals[v];
                x = i;
                y = idxs[v];
            }
        }

        if (cur >= 0)
            cout << x + 1 << " " << y + 1 << '\n';
        else
            cout << "No\n";
    }

    return 0;
}
