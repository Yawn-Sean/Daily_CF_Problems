#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

using Z = DynModInt<0>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    int l = 0, r = 1E9;
    std::set<int> st;
    st.insert(l);
    st.insert(r);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int p;
        std::string s;
        std::cin >> s >> p;

        if (s == "ADD") {
            st.insert(p);
        } else {
            if (p < l || p > r) {
                std::cout << 0 << "\n";
                return 0;
            }
            if (p > l && p < r) {
                cnt++;
            }
            auto it = st.find(p);
            l = *(--it);
            ++it;
            r = *(++it);
            st.erase(--it);
        }
    }

    Z ans = 1;
    for (auto &x : st) {
        if (x > l && x < r) {
            ans = ans + 1;
        }
    }

    std::cout << ans * power(Z(2), cnt) << "\n";

    
    return 0;
}
