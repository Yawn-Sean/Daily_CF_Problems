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

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int64_t x, d;
    cin >> x >> d;
    int64_t cur = 1;
    vector<int64_t> res;
    per(i, 31, 1) {
        while (x >= (1 << i) - 1) {
            rep(j, 0, i)   {
                res.push_back(cur);
            }
            x -= (1 << i) - 1;
            cur += d + 1;
        }
    }
    cout << int(res.size()) << '\n';
    for (auto i : res) {
        cout << i << " ";
    }
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

/*
https://codeforces.com/problemset/problem/960/C
*/