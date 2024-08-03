#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

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

/*
address:https://codeforces.com/problemset/problem/623/A
题意
给一个图，给这些图标号，问有没有一个合法的标号

标号就只能标a,b,c。

然后a会和ab连边，b和abc都连边，c和bc连边

题解：
首先把那种入度为n-1的点染成b，然后再随便选一个没有染成b的点当成a，然后和a连边的就是a，没有和a连边的就是c

扫一遍就可以确认所有点的颜色，最后再n^2check一下
*/