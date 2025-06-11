#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1'000'000'007;

void solve() {
    std::string a, b, c;
    std::cin >> a >> b >> c;
    std::vector<int> cnta(26), cntb(26), cntc(26);

    for (char ch : a)
        ++ cnta[ch - 'a'];

    for (char ch : b)
        ++ cntb[ch - 'a'];

    for (char ch : c)
        ++ cntc[ch - 'a'];

    int cb = 0, cc = 0, ma = 0;

    for (int i = 0; i <= a.size() / b.size(); ++ i) {
        bool ok = true;

        int s = i, mi = -1;

        for (int j = 0; j < 26; ++ j) 
            if (cntb[j] && cnta[j] / cntb[j] < i) {
                ok = false;
                break;
            }
            else if (cntc[j]){
                if (mi == -1)
                    mi = (cnta[j] - i * cntb[j]) / cntc[j];
                else
                    mi = std::min(mi, (cnta[j] - i * cntb[j]) / cntc[j]);
            }

        if (!ok) break;

        if (~mi)
            s += mi;

        if (s > ma)
            ma = s, cb = i, cc = ~mi ? mi : 0;
    }

    for (int i = 0; i < cb; ++ i)
        std::cout << b;

    for (int i = 0; i < cc; ++ i)
        std::cout << c;

    for (int i = 0; i < 26; ++ i)
        for (int j = 0; j < cnta[i] - cb * cntb[i] - cc * cntc[i]; ++ j)
            std::cout << (char)(i + 'a');
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}