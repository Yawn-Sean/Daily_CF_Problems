#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    if (N % 2 == 0) {
        N--;
        int l = N / 2, r = (N + 1) / 2;
        if (S[l] == 'B' || S[r] == 'B') {
            std::cout << "Doludu\n";
            return;
        }
    } else {
        N--;
        int m = N / 2, l = m - 1, r = m + 1;
        if (S[m] == 'B' && (S[l] == 'B' || S[r] == 'B')) {
            std::cout << "Doludu\n";
            return;
        }
    }
    std::cout << "DoIudu\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
