#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        deg[u - 1]++;
        deg[v - 1]++;
    }
    std::vector<bool> isl(n);
    std::vector<int> id(n);
    int idl = 0, idi = 0;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            isl[i] = true;
            id[i] = idl++;
        } else {
            id[i] = idi++;
        }
    }
    std::vector<i64> b(idl);
    for (int i = 0; i < n; i++) if (isl[i]) b[id[i]] = a[i]; 
    std::vector<i64> t(2 * idi), d(2 * n);
    auto sett = [&](int i, i64 x) -> void { for (t[i += idi] = x; i >>= 1; ) t[i] = std::gcd(t[i << 1], t[i << 1 | 1]); };
    auto setd = [&](int i, i64 x) -> void { for (d[i += n] = x; i >>= 1; ) d[i] = std::gcd(d[i << 1], d[i << 1 | 1]); };
    for (int i = 0; i < n; i++) if (!isl[i]) sett(id[i], a[i]);
    for (int i = 0; i < n; i++) setd(i, a[i]);
    int q;
    std::cin >> q;
    while (q--) {
        int i;
        std::cin >> i;
        i--;
        i64 x;
        std::cin >> x;
        if (isl[i]) b[id[i]] = x;
        else sett(id[i], x);
        setd(i, x);
        if (d[1] > 1) {
            std::cout << "No\n";
            continue;
        } 
        if (idl > 30) std::cout << "Yes\n";
        else {
            i64 g = n == 2 ? 0 : t[1];
            std::vector<i64> suf(idl + 1);
            for (int i = idl - 1; i >= 0; i--) suf[i] = std::gcd(b[i], suf[i + 1]);
            i64 pre = 0;
            bool f = false;
            for (int i = 0; i < idl; i++) {
                if (std::gcd(std::gcd(pre, g), suf[i + 1]) == 1) {
                    f = true;
                    break;
                }
                pre = std::gcd(pre, b[i]);
            }
            std::cout << (f ? "Yes\n" : "No\n");
        }
    }
}
