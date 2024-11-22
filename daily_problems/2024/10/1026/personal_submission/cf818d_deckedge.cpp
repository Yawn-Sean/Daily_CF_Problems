#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using i64 = long long;
using pi = pair<int, int>;

struct Node {
    int val, cnt;
    Node(int x = 0, int y = 0) : val(x), cnt(y) {}
    bool operator<(const Node& b) const {
        return val < b.val;
    }
};

inline int read() {
    int x;
    cin >> x;
    return x;
}


void solve() {
    int n = read(), A = read(), cnt = 0;
    const int N = 1e6 + 7;
    set<Node> vis;
    set<Node>::iterator it;
    ve<int> a(N);

    rep(i, 0, n) {
        int cur = read();
        if (A == cur) {
            cnt++;
            while (int(vis.size()) && (*vis.begin()).cnt < cnt) {
                a[(*vis.begin()).val] = -1;
                vis.erase(vis.begin());
            }
        } else {
            Node tmp;
            if (a[cur] > 0) {
                it = vis.lower_bound(Node(cur));
                tmp = *it;
                vis.erase(it);
                tmp.cnt++;
                vis.insert(tmp);
            } else if (!a[cur] && !cnt) {
                a[cur] = 1;
                tmp = Node(cur, 1);
                vis.insert(tmp);
            }
        }
    }
    if (int(vis.size())) {
        cout << (*vis.begin()).val << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}

//https://codeforces.com/problemset/problem/818/D
