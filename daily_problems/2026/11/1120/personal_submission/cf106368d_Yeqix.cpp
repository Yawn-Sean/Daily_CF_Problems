#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

void print(vector<array<int, 2>> ans) {
    cout << ans.size() << "\n";
    for (const auto& [l, r] : ans) {
        cout << l << " " << r << "\n";
    }

    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<i64> out(20000), st;
    int cnt = 0;

    for (int i = 1; i <= t; i++) {
        char c;
        int x;
        cin >> c >> x;

        vector<int> v;
        vector<array<int, 2>> ans;
        if (c == '+') {
            out[++cnt] = x;
            v.push_back(cnt);
        } else {
            ans.push_back({2, st.back()}), st.pop_back();
        }

        int len = ((i & -i) << 1) - 1;
        while (len && !st.empty()) {
            v.push_back(st.back());
            ans.push_back({2, st.back()});
            st.pop_back();
            len--;
        }

        rgs::sort(v, [&](int x, int y) { return out[x] < out[y]; });

        while (!v.empty()) {
            st.push_back(v.back());
            ans.push_back({1, v.back()});
            v.pop_back();
        }

        print(ans);
    }
    return 0;
}