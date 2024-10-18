#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
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
    int n = red(), pt = 0;
    ve<int> a(n), b(n), vis(n + 1);
    generate(all(a), red);
    generate(all(b), red);
    for (auto& x : a) {
        if (x == b[pt]) {
            pt++;
        } else {
            vis[x]++;
        }
        while (0 < pt && pt < n && b[pt] == b[pt - 1] && vis[b[pt]]) {
            vis[b[pt++]]--;
        }
    }

    cout << (pt == n ? "YES\n" : "NO\n");
}
  
int main() {  
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = red();
    while (t--) {  
        solve();
    }  
    return 0;  
}

/*
https://codeforces.com/problemset/problem/1672/D
*/