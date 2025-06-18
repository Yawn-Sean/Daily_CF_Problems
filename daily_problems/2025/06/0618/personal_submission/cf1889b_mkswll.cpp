#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin >> _;
    while(_--) {
        int n, c;
        cin >> n >> c;
        vector<ll> a(n + 1);
        ll sm = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            sm += a[i];
        }
        vector<pair<ll, ll>> need;
        for(int i = 2; i <= n; ++i) {
            need.emplace_back((ll) i * c - a[i], a[i]);
        }
        sort(need.begin(), need.end());
        ll cur = a[1];
        bool ans = 1;
        for(auto [sm, val] : need) {
            if(cur < sm) {
                ans = 0;
                break;
            }
            cur += val;
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}
