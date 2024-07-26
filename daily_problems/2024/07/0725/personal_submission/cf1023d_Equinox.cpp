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
    int n;
    std::cin >> n;
    std::vector<int> adj(26, -1), vis(26, -1);
    for (int i = 0; i < n; ++ i) {
        std::string s;
        std::cin >> s;
        int u = -1;
        for (char ch : s) {
            int v = ch - 'a';
            if (vis[v] == i) {   // 重复字符
                std::cout << "NO\n";
                return;
            }
            vis[v] = i;
            if (~u) {
                if (~adj[u] && adj[u] != v) {
                    std::cout << "NO\n";

                    return;
                }
                adj[u] = v;
            }
            u = v;
        }
    }   
    std::vector<bool> in(26);
    for (int x : adj) {
        if (~x) {
            if (in[x]) {
                std::cout << "NO\n";
                return;
            }
            in[x] = true;
        }
    }

    std::vector<int> res;
    for (int i = 0; i < 26; ++ i) {
        if (!in[i] && ~vis[i]) {
            int u = i;
            vis[i] = -1;
            res.push_back(u);
            while (~adj[u])
                u = adj[u], vis[u] = -1, res.push_back(u);
        }
    }

    for (int i = 0; i < 26; ++ i)
        if (~vis[i]) {
            std::cout << "NO\n";
            return;
        }

    for (int x : res) std::cout << (char)(x + 'a');
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