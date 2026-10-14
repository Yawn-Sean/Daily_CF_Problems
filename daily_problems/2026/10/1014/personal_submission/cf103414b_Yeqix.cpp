#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

array<i64, 3> query(int l, int r) {
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    i64 s, cl, cr;
    cin >> s >> cl >> cr;
    return {s, cl, cr};
}

void print(vector<i64>& a) {
    cout << "!\n";
    for (int i = 1; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<array<i64, 2>> st;
    vector<i64> a(n + 1), pre(n + 1);
    for (int l = 1, r = 1; r <= n; r++) {
        while (st.count({l, r})) {
            l++;
        }
        auto [s, cl, cr] = query(l, r);
        a[r] = s - pre[r - 1] + pre[l - 1];
        pre[r] = pre[r - 1] + a[r];
        st.insert({cl, cr});
    }

    print(a);
    return 0;
}