#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int mod = 998244353;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    int pre = -1;
    int last = mp[a[0]].back();
    int k = 1;
    for (int i = 1; i < n; i++) {
        if (i <= last) {
            last = max(last, mp[a[i]].back());
        } else {
            k++;
            last = mp[a[i]].back();
        }
    }
    int ans = 1;
    for (int i = 2; i <= k; i++)
        ans = (ans * 2) % mod;
    cout << ans << endl;
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