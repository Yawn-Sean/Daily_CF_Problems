#include <bits/stdc++.h>
using namespace std;
int n, a[100010];
set<int> st[100010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        st[a[i]].insert(i);
    }
    sort(a + 1, a + n + 1);
    int pos = 1;
    long long ans = n;
    for (int i = 1; i <= n; i++) {
        auto it = st[a[i]].lower_bound(pos);
        if (it == st[a[i]].end()) {
            ans += n - i + 1;
            pos = 1;
            it = st[a[i]].lower_bound(pos);
        }
        pos = *it;
        st[a[i]].erase(it);
    }
    cout << ans;
    return 0;
}