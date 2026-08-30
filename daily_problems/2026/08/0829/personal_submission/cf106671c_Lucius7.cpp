#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 998244353;

void solve() {
    int n;
    std::cin >> n;

    std::deque<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int sum = std::accumulate(a.begin(), a.end(), 0LL);
    sum = (sum % P + P) % P;

    std::deque<int> frnt, bck;
    bool f = false;
    int q;
    std::cin >> q;
    while (q--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int x;
            std::cin >> x;
            if (frnt.empty()) {
                if (!f) {
                    a.push_back(x);
                } else {
                    a.push_front(x);
                }
                sum += x;
                sum = (sum % P + P) % P;
            } else {
                if (!f) {
                    bck.push_front(x);
                } else {
                    frnt.push_front(x);
                }
                sum += x;
                sum = (sum % P + P) % P;
            }
        } else if (op == 2) {
            int t;
            if (frnt.empty()) {
                if (!f) {
                    t = a.back();
                    a.pop_back();
                } else {
                    t = a.front();
                    a.pop_front();
                }
            } else {
                if (!f) {
                    t = bck.front();
                    bck.pop_front();
                } else {
                    t = frnt.front();
                    frnt.pop_front();
                }
            }
            sum -= t;
            sum = (sum % P + P) % P;
        } else if (op == 3) {
            f = !f;
        } else if (op == 4) {
            if (frnt.empty()) {
                auto b = a;
                for (int i = 0; i < b.size(); i++) {
                    a.push_back(b[i]);
                }
                if (a.size() > q) {
                    for (int i = 0; i < q; i++) {
                        bck.push_back(a[a.size() - 1 - i]);
                    }
                    for (int i = 0; i < q; i++) {
                        frnt.push_back(a[i]);
                    }
                }
            } 
            sum *= 2;
            sum = (sum % P + P) % P;
        } else {
            std::cout << sum << "\n";
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
