#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<i64> a(n);
    std::vector<int> b(n);
    for (int i = 0; i < n; ++ i) 
        std::cin >> a[i];    
    for (int i = 0; i < n; ++ i)
        std::cin >> b[i];

    i64 sum = 0;
    std::vector<int> id(n);
    std::iota(id.begin(), id.end(), 0);

    std::ranges::sort(id, [&a](int i, int j) -> bool {
        return a[i] < a[j];
    });

    std::vector<int> st, buf;

    for (int i = 0, j = 0; i < n; ) {
        i64 tot = 0;
        while (j < n && a[id[i]] == a[id[j]])
            tot += b[id[j ++]];
        if (j - i > 1) {
            sum += tot;
            st.insert(st.end(), id.begin() + i, id.begin() + j);
        }
        else {
            buf.insert(buf.end(), id.begin() + i, id.begin() + j);
        }
        i = j;
    }

    for (int i : buf) {
        bool ok = false;
        for (int j : st) {
            if ((a[i] & a[j]) == a[i]) {
                ok = true;
                break;
            }
        }
        if (ok) {
            st.push_back(i);
            sum += b[i];
        }
    }

    std::cout << sum;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef DEBUG
    int cur = clock();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }
#ifdef DEBUG
    std::cerr << "run-time: " << clock() - cur << '\n';
#endif
    return 0;
}