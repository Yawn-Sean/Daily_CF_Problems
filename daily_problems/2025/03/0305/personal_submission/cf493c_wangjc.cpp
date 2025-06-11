#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n, k, p;
    cin >> n >> k >> p;
    
    vector<vector<int>> ans(k);
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x & 1) odd.push_back(x);
        else even.push_back(x);
    }

    k -= p;
    if (odd.size() < k || (odd.size() - k) % 2 == 1 || (odd.size() - k) / 2 + even.size() < p) {
        cout << "NO\n";
        return;
    }
    int l = 0;
    for (int i = 0; i < k; i++) {
        ans[i].push_back(odd[i]);
    }
    l = k;
    for (int i = k; i < odd.size(); i += 2) {
        ans[l % (k + p)].push_back(odd[i]);
        ans[l++ % (k + p)].push_back(odd[i + 1]);
    }
    for (int i : even) {
        ans[l++ % (k + p)].push_back(i);
    }

    cout << "YES\n";
    for (auto i : ans) {
        cout << i.size() << " ";
        for (auto j : i) cout << j << " ";
        cout << "\n";
    }
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
