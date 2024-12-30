#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int x, d;
    cin >> x >> d;
    vector<ll> mi(32);
    for (int i = 1; i < 32; i++)
        mi[i] = pow(2ll, i) - 1;
    vector<ll> ans;
    ll st = 1;
    while (x) {
        int pos = upper_bound(mi.begin(), mi.end(), x) - mi.begin() - 1;
        for (int i = 1; i <= pos; i++) {
            ans.push_back(st);
        }
        x -= mi[pos];
        st += d + 1;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
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