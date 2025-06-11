#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> l(m), r(m);
    set<pair<int, int>> st;

    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
        if (l[i] > r[i]) swap(l[i], r[i]);
        st.emplace(l[i], r[i]);
    }

    int tmp = n;
    for (int i = 2; i <= n; i++)
        if (tmp % i == 0) {
            while (tmp % i == 0) tmp /= i;
            int x = n / i;
            bool flag = true;
            for (int j = 0; j < m; j++) {
                int nl = (l[j] + x) % n, nr = (r[j] + x) % n;
                if (nl > nr) swap(nl, nr);
                if (!st.count({nl, nr})) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "Yes";
                return 0;
            }
        }
    cout << "No";
    return 0;
}