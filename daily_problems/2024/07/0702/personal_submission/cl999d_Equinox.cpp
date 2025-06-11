#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 1e9 + 7, P = 998244353;


struct Node {
    int x, pre, nxt, id;
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    int k = n / m;
    std::vector<int> a(n);
    std::vector<std::vector<int>> id(m);

    for (int i = 0; i < n; i ++ ) {
        std::cin >> a[i];
        id[a[i] % m].push_back(i);
    }

    std::vector<int> st;
    st.reserve(n);
    i64 res = 0;

    for (int i = 0; i < 2 * m; i ++ ) {
        int rem = i % m;
        while (st.size() && id[rem].size() < k) {
            int j = st.back();
            st.pop_back();
            id[rem].push_back(j);
            int inc = (rem - a[j] % m + m) % m;
            res += inc, a[j] += inc;
        }
        while (id[rem].size() > k) {
            st.push_back(id[rem].back());
            id[rem].pop_back();
        }    
    }
    std::cout << res << '\n';
    for (int x : a) std::cout << x << ' ';
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}