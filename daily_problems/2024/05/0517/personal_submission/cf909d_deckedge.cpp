#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

const int N = 1e6 + 7;
int n, len;

struct nod {
    int cnt, val;
}q[N];

inline int red() {
    int x;
    cin >> x;
    return x;
}

void update() {
    len = n; n = 0;
    rep(i, 1, len + 1) {
        if (q[i].cnt > 0) {
            if (q[i].val == q[n].val) {
                q[n].cnt += q[i].cnt;
            } else {
                q[++n] = q[i];
            }
        }
    }
}

void turn() {
    int res = 0;
    while (n > 1) {
        res++;
        rep(i, 2, n) {
            q[i].cnt -= 2;
        }
        q[1].cnt -= 1, q[n].cnt -= 1;
        update();
    }
    cout << res << '\n';
}

void solve() {
    string s;
    cin >> s;
    n = s.size();
    rep(i, 1, n + 1) {
        q[i].val = s[i - 1] - 'a';
        q[i].cnt = 1;
    }
    q[0].val = -1, q[0].cnt = 0;
    update();
    turn();
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
