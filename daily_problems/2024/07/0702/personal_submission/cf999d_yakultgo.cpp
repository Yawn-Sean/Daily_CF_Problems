#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int k = n / m;
    vector<int> pos[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i] % m].push_back(i);
    }
    ll ans = 0;
    stack<int> st;
    for (int i = 0; i < 2 * m; i++) {
        int x = i % m;
        if (pos[x].size() == k) continue;
        while (st.size() && pos[x].size() < k) {
            int t = st.top();
            st.pop();
            int v = (x - a[t] % m + m) % m;
            ans += v;
            a[t] += v;
            pos[x].push_back(t);
        }
        while (pos[x].size() > k) {
            int t = pos[x].back();
            pos[x].pop_back();
            st.push(t);
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
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