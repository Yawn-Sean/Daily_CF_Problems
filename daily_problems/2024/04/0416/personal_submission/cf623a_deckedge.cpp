#include <bits/stdc++.h>
using namespace std;

inline int red() {
    int x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = red(), m = red(), i, j;
    vector<vector<int>> g(n, vector<int> (n));
    vector<int> mark(n), cnt(n);

    while (m--) {
        int a = red(), b = red();
        a--, b--;
        g[a][b] = 1;
        g[b][a] = 1;
        cnt[b]++;
        cnt[a]++;
    }
    bool fail = false;
    for (i = 0; i < n; ++i) {
        if (cnt[i] == n - 1) {
            mark[i] = 1;
        }
    }

    int idx = -1;
    for (i = 0; i < n; ++i) {
        if (!mark[i]) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "Yes\n";
        for (i = 0; i < n; ++i) {
            cout << "b";
        }
    } else {
        for (i = 0; i < n; ++i) {
            if (i == idx) {
                continue;
            } 
            if (!g[i][idx]) {
                mark[i] = 2;
            }
        }
        for (i = 0; i < n; ++i) {
            if (fail) {
                break;
            }
            for (j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                if (g[i][j]) {
                    if (abs(mark[i] - mark[j]) > 1) {
                        fail = true;
                        break;
                    }
                } else {
                    if (abs(mark[i] - mark[j]) <= 1) {
                        fail = true;
                        break;
                    }
                }
            }
        }
        if (fail) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for (i = 0; i < n; ++i) {
                if (!mark[i]) {
                    cout << 'a';
                } else if (mark[i] == 1) {
                    cout << 'b';
                } else {
                    cout << 'c';
                }
            }
        }
        cout << '\n';
    }

    return 0;
}