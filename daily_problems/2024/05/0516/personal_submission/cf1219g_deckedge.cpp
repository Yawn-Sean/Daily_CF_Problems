#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define pb push_bbck
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

int n, m;
inline int pos(int x, int y) {
    return (x - 1) * m + y;
}

int a[100004], b[100004];
int64_t col[100004], row[100004];

priority_queue<int64_t, vector<int64_t>, greater<int64_t> > q;
int64_t getcol() {
    while(!q.empty()) {
        q.pop();
    }
    rep(i, 1, m + 1) {
        int64_t cur = col[i];
        if (q.size() < 4) {
            q.push(cur);
        } else if (q.top() < cur) {
            q.pop();
            q.push(cur);
        }
    }
    int64_t ret = 0;
    while(!q.empty()){
        ret += q.top();q.pop();
    }
    return ret;
}
int64_t getrow() {
    while(!q.empty()) {
        q.pop();
    }
    rep(i, 1, n + 1) {
        int64_t cur = row[i];
        if (q.size() < 4) {
            q.push(cur);
        } else if (q.top() < cur) {
            q.pop();
            q.push(cur);
        }
    }
    int64_t ret = 0;
    while (!q.empty()) {
        ret += q.top();
        q.pop();
    }
    return ret;
}
int64_t decol() {
    int64_t ret = 0;
    rep(i, 1, m + 1) {
        int64_t cur = col[i];
        while (!q.empty()) {
            q.pop();
        }
        rep(j, 1, n + 1) {
            if (q.size() < 3) {
                q.push(row[j] - b[pos(j, i)]);
            } else if (q.top() < row[j] - b[pos(j, i)]) {
                q.pop();
                q.push(row[j] - b[pos(j, i)]);
            }
        }
        while(!q.empty()) {
            cur += q.top();
            q.pop();
        }
        ret = max(cur, ret);
    }
    return ret;
}
int64_t derow() {
    int64_t ret = 0;
    rep(i, 1, n + 1) {
        int64_t cur = row[i];
        while (!q.empty()) {
            q.pop();
        }
        rep (j, 1, m + 1) {
            if (q.size() < 3) {
                q.push(col[j] - b[pos(i, j)]);
            } else if (q.top() < col[j] - b[pos(i, j)]) {
                q.pop();
                q.push(col[j] - b[pos(i, j)]);
            }
        }
        while(!q.empty()) {
            cur += q.top();
            q.pop();
        }
        ret = max(cur, ret);
    }
    return ret;
}
int64_t work() {
    int64_t ret = 0;
    rep(i, 1, n + 1) {
        rep(j, i + 1, n + 1) {
            int64_t cur = row[i] + row[j];
            while(!q.empty()) {
                q.pop();
            }
            rep(k, 1, m + 1) {
                if (q.size() < 2) {
                    q.push(col[k] - b[pos(i, k)] - b[pos(j, k)]);
                } else if (q.top() < col[k] - b[pos(i, k)] - b[pos(j, k)]) {
                    q.pop();
                    q.push(col[k] - b[pos(i, k)] - b[pos(j, k)]);
                }
            }
            while (!q.empty()) {
                cur += q.top();
                q.pop();
            }
            ret = max(cur, ret);
        }
    }
    return ret;
}

void solve() {
    n = red(), m = red();
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            a[pos(i, j)] = red();
        }
    }
    if (n > m) {
        rep(i, 1, n + 1) {
            rep(j, 1, m + 1) {
                b[(j - 1) * n + i] = a[pos(i, j)];
            }
        }
        swap(n, m);
    } else {
        rep(i, 1, n + 1) {
            rep(j, 1, m + 1) {
                b[pos(i, j)] = a[pos(i, j)];
            }
        }
    }
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            int v = b[pos(i, j)];
            row[i] += v;
            col[j] += v;
        }
    }
    int64_t res = 0;
    res = max(res, getcol());
    res = max(res, getrow());
    res = max(res, decol());
    res = max(res, derow());
    res = max(res, work());
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
