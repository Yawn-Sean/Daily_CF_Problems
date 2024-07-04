#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 1e9 + 7, P = 998244353;


struct Node {
    int x, pre, nxt, id;
};

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> mp(n + 1), b(k);
    std::vector<Node> a(n + 1);
    for (int i = 1, x; i <= n; i ++ ) std::cin >> x, a[i] = { x, i - 1, i + 1 }, mp[a[i].x] = i;
    a[n].nxt = 0;
    int res = 1;
    for (int i = 0, x; i < k; i ++ ) {
        std::cin >> b[i];
        a[mp[b[i]]].id = i + 1;
    }
    for (int x : b) {
        int p = mp[x];
        int cnt = (a[p].pre && a[a[p].pre].id < a[p].id) + (a[p].nxt && a[a[p].nxt].id < a[p].id);
        if (!cnt) {
            res = 0;
            break;
        }
        res = 1LL * cnt * res % P;
        a[a[p].pre].nxt = a[p].nxt, a[a[p].nxt].pre = a[p].pre;
    }
    std::cout << res << '\n'; 
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_ --)
        solve();
    return 0;
}