#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128_t;
using u64 = unsigned long long;

std::string Y = "YES", T = "NO";

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> q(n), s(n);
    for(int i = 0; i < n; i++) std::cin >> q[i], q[i]--;
    for(int i = 0; i < n; i++) std::cin >> s[i], s[i]--;
    bool ok = false;
    std::vector<int> c1(n);
    for(int i = 0; i < n; i++) {
        c1[q[i]] = i;
    }  
    auto checkinv = [&](std::vector<int>& a, std::vector<int>& c1)-> bool {
        std::vector<int> cc(n);
        for(int i = 0; i < n; i++) {
            cc[i] = a[c1[i]];
        }
        bool ans = 1;
        for(int i = 0; i < n; i++) {
            if(cc[i] != s[i]) ans = 0; 
        }
        return ans;
    };
    auto eq = [&](std::vector<int>& a, std::vector<int>& b) {
        bool ans = 1;
        for(int i = 0; i < n; i++) if(a[i] != b[i]) ans = 0;
        return ans;
    };

    auto check = [&](std::vector<int>& a, std::vector<int>& b, std::vector<int>& c, std::vector<int>& c1) {

        

        {
            bool f = 0;
            for(int i = 0; i < n; i++) {
                if(a[i] != b[i]) f = 1;
            }
            if(!f) return;
        }
        if(k & 1) {
            std::vector<int> cc = a;
            for (auto& x : cc) x = c[x];
            if (eq(cc, b)) {
                if (k == 1) {
                    ok = 1;
                    return;
                } else {
                    bool ff = checkinv(a, c1); 
                    if(!ff) {
                        ok = 1;
                    }
                    return;
                }
            }
            a = std::move(cc);
        }

        for(int i = k & 1; i <= k; i += 2) {
            if(eq(a, b)) {
                ok = 1;
            }

            for(auto& x : a) x = c[x];
            if(eq(a, b)) {
                return;
            }
            for(auto& x : a) x = c[x];
        }
    };

    std::vector<int> s1(n);
    for(int i = 0; i < n; i++) s1[i] = i;
    check(s1, s, q, c1);
    for(int i = 0; i < n; i++) s1[i] = i;
    check(s1, s, c1, q);
    std::cout << (ok ? Y : T) << "\n";
    
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t = 1;  
    // std::cin >> t;
    while (t--)
        solve();
    return 0;
}
