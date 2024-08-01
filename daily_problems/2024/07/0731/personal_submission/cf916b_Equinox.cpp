#include <bits/stdc++.h>
#include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1e9 + 7;
constexpr i64 inf64 = 1e18 + 7;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    std::map<int, int> cnt;
    int pcnt = 0;
    for (int i = 63; ~i; -- i)
        if (n >> i & 1)
            ++ cnt[i], ++ pcnt;

    if (pcnt > k) {
        std::cout << "No\n";
        return;
    }

    for (int i = 63; i >= -63; -- i)
        if (pcnt + cnt[i] <= k)
            pcnt += cnt[i], cnt[i - 1] += cnt[i] * 2, cnt[i] = 0;
        else
            break;

    std::multiset<int> st;
    for (int i = 63; i >= -63; -- i)
        for(int j = 0; j < cnt[i]; ++ j) 
            st.insert(i);

    while (st.size() < k) {
        int fi = *st.begin();
        st.erase(st.begin());
        st.insert(fi - 1), st.insert(fi - 1);
    }

    std::cout << "Yes\n";
    for (auto it = st.rbegin(); it != st.rend(); ++ it)
        std::cout << *it << ' ';
    std::cout << '\n';
}

auto FIO = []{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
} ();

int main() {
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif     

    int t = 1;
    // std::cin >> t;
    while (t --)
        solve();

    return 0;
}