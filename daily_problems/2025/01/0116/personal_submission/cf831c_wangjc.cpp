#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n, k;
    cin >> n >> k;
    set<int> st;
    int cur = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cur += a[i];
        st.insert(cur);
    }
    vector<int> b(k);
    for (int i = 0; i < k; i++) cin >> b[i];
    int ans = 0;
    for (auto x : st) {
        cur = b[0] - x;
        bool ok = 1;
        for (int i = 1; i < k; i++) {
            if (st.find(b[i] - cur) == st.end()) {
                ok = 0;
                break;
            } 
        }
        if (ok) ans++;
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
