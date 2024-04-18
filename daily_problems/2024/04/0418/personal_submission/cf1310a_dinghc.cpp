#include <bits/stdc++.h>

using namespace std;
constexpr int MXN = 200000;
int a[MXN];
int t[MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    
    ranges::sort(indices, [&] (int const x, int const y) {
        return a[x] < a[y];
    });

    long long ans = 0LL;
    multiset<int> st;
    long long sum = 0LL;
    int curr = 0;
    for (int i = 0; i < n; ) {
        int j = indices[i];
        if (st.empty() || curr == a[j]) {
            st.insert(t[j]);
            sum += t[j];
            curr = a[j];
            i++;
        } else {
            auto it = st.end();
            sum -= *--it;
            st.erase(it);
            ans += sum;
            curr++;
        }
    }
    while (!st.empty()) {
        auto it = st.end();
        sum -= *--it;
        st.erase(it);
        ans += sum;
    }

    cout << ans << "\n";

    return 0;
}

