#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    set<int> st;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        st.insert(x);
    }
   
    while (true) {
        bool f = false;
        int fi = *st.rbegin(), se = 0, tmp = fi, now;
        if (n > 1) {
            auto it = st.rbegin(); it--;
            se = *(it);
        }
        while (tmp > 1) {
            tmp /= 2;
            if (st.count(tmp)) continue;
            f = true; now = tmp;
            if (f < se) break;
        }
        if (!f) break;
        st.erase(fi);
        st.insert(now);
    }

    for (int x: st)
        cout << x << " ";

    return 0;
}