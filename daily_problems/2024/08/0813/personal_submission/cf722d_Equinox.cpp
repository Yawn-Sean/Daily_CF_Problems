#include <bits/stdc++.h>
// #include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1E-9;
constexpr int P = 1'000'000'007;

struct custom_hash {
    static u64 splitmix64(u64 x) {
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        return x; 
    }
    size_t operator () (u64 x) const {
        static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); // 时间戳
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++ i) std::cin >> a[i];


    std::unordered_set<u64, custom_hash> st(a.begin(), a.end());

    std::priority_queue<int> pq(a.begin(), a.end());


    while (true) {
        int t = pq.top();
        
        while (st.contains(t))
            t /= 2;

        if (!t) break;
        
        st.erase(pq.top());
        pq.pop();
        pq.push(t);
        st.insert(t);
    }

    for (int x : st)
        std::cout << x << ' ';
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