#include <bits/stdc++.h>
#define REP(i, j) for (int i = 0; i < j; ++i)
using namespace std;
using ll = int64_t;
const int LIM = 2e5 + 5;
int vn[LIM], vm[LIM];
void solve() {
    int n, m, k, tmp;
    cin >> n >> m >> k;
    vector<array<int, 2>> vk(k);
    REP(i, n) { cin >> vn[i]; }
    REP(i, m) { cin >> vm[i]; }
    REP(i, k) { cin >> vk[i][0] >> vk[i][1]; }
    ll res = 0;
    sort(vn, vn + n);
    sort(vm, vm + m);
    sort(vk.begin(), vk.end(),
         [](array<int, 2> a, array<int, 2> b) { return a[0] < b[0]; });
    int cur = 0;
    REP(i, n) {
        unordered_map<int, ll> s;
        ll xt = 0;
        while (cur < k && vk[cur][0] < vn[i]) {
            res += xt - s[vk[cur][1]];
            s[vk[cur][1]]++;
            xt++;
            cur++;
        }
        while (cur < k && vk[cur][0] == vn[i])
            cur++;
    }
    sort(vk.begin(), vk.end(),
         [](array<int, 2> a, array<int, 2> b) { return a[1] < b[1]; });
    cur = 0;
    REP(i, m) {
        unordered_map<int, ll> s;
        ll xt = 0;
        while (cur < k && vk[cur][1] < vm[i]) {
            res += xt - s[vk[cur][0]];
            s[vk[cur][0]]++;
            xt++;
            cur++;
        }
        while (cur < k && vk[cur][1] == vm[i])
            cur++;
    }
    cout << res << '\n';
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}