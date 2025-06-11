#include <bits/stdc++.h>
#define sc scanf
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
constexpr int inf32 = 1e9 + 7;
constexpr i64 inf64 = 1e18 + 7;
constexpr int P = 998244353;
constexpr double eps = 1e-6;

// #define DEBUG

void solve()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n), L(q + 1, -1), R(q + 1, -1);
    int ma = -1, mi = inf32;

    for (int i = 0; i < n; ++ i) {
        std::cin >> a[i], ma = std::max(ma, a[i]), mi = std::min(mi, a[i]);
        if (L[a[i]] == -1) L[a[i]] = i;
        R[a[i]] = i;
    }

    std::set<int> st;
    for (int i = 0; i < n; ++ i) {
        if (!a[i]) {
            if (ma < q)
                a[i] = q, ma = q;
            else if(st.size())
                a[i] = *std::prev(st.end());
            else
                a[i] = 1;
        }
        else {
            if (L[a[i]] == i && i < R[a[i]]) st.insert(a[i]);
            if (R[a[i]] == i && L[a[i]] < i) st.erase(a[i]);
            if (st.size() && a[i] < *std::prev(st.end())) {
                std::cout << "NO\n";
                return;
            }    
        }
    }

    std::cout << "YES\n";
    for (int x : a)
        std::cout << x << ' ';

}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    while (_--)
        solve();
    return 0;
}