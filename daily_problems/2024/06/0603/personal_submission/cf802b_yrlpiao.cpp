#include <iostream>
#include <vector>
#include <set>
#include <array>
using namespace std;

void yrlpSolve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 10), vis(n + 10), nxt(n + 10), pos(n + 10, n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    set<array<int, 2>, greater<>> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[a[i]] == 1) {
            s.erase({i, a[i]});
            s.insert({nxt[i], a[i]});
            continue;
        }
        if (s.size() == k) {
            vis[(*s.begin())[1]] = 0;
            s.erase(s.begin());
        }
        vis[a[i]] = 1;
        s.insert({nxt[i], a[i]});
        ans += 1;
    }
    cout << ans;
    return; 
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
