#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    int ans = 1;
    map<int, int> cnt;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x = cnt[a[i]];
        if (mp.count(x) && --mp[x] == 0) mp.erase(x);
        cnt[a[i]]++;
        mp[x + 1]++;
        if (mp.size() > 2) continue;
        if (mp.size() == 2) {
            auto it = mp.begin();
            auto it2 = mp.rbegin();
            if (it->first == 1 && it->second == 1) ans = i + 1;
            if (it2->first == it->first + 1 && it2->second == 1) ans = i + 1;
        } else {
            if (mp.begin()->first == 1 || mp.begin()->second == 1) ans = i + 1;
        }
    }
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