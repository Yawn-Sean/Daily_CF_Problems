#include <bits/stdc++.h>
// #include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1E-9;

void solve() {
    int n, a, b, k;
    std::cin >> n >> a >> b >> k;

    std::string s;
    std::cin >> s;

    std::vector<int> id;

    for (int i = 0, c = 0; i < n; ++ i) {
        if (s[i] == '0') { 
            if (++ c == b) {
                c = 0, id.push_back(i);
            }
        }
        else
            c = 0;
    }

    while (-- a)
        id.pop_back();
    std::cout << id.size() << '\n';
    
    for (int x : id)
        std::cout << x + 1 << ' ';
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