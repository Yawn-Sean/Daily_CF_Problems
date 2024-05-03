#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int a[N], op[N], x[N];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> op[i] >> x[i];
    vector<int> dq;
    for (int i = m; i >= 1; i--) {
        if (!dq.empty() && x[i] <= x[dq.back()]) continue;
        dq.push_back(i);
    }
    reverse(dq.begin(), dq.end());
    multiset<int> st;
    for (int i = 1; i <= n; i++) {
        if (i <= x[dq[0]])
            st.insert(a[i]);
    }
    int pre = x[dq[0]];
    int dir = op[dq[0]] == 1 ? 1 : -1;
    for (int i = 1; i < dq.size(); i++) {
        int cur = x[dq[i]];
        for (int j = pre; j > cur; j--) {
            // 从右边删除
            if (dir == 1) {
                a[j] = *st.rbegin();
                st.erase(st.find(a[j]));
            } else {
                a[j] = *st.begin();
                st.erase(st.find(a[j]));
            }
        }
        dir = op[dq[i]] == 1 ? 1 : -1;
        pre = cur;
    }
    for (int i = pre; i >= 1; i--) {
        if (dir == 1) {
            a[i] = *st.rbegin();
            st.erase(st.find(a[i]));
        } else {
            a[i] = *st.begin();
            st.erase(st.find(a[i]));
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}