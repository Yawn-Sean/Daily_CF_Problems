#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
vector<pair<int, int>> b[3000];
vector<int>cnt(3000, 0);
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;
        p--;
        if (p != 0)
            arr.emplace_back(c, i);
        cnt[p]++;
        b[p].push_back({c, i});
    }
    for (int i = 0; i < m; i++)
        sort(b[i].begin(), b[i].end());
    sort(arr.begin(), arr.end());
    vector<bool> buy(n, false);
    ll ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        ll sum = 0;
        int people = cnt[0];
        for (int j = 1; j < m; j++) {
            if (cnt[j] < i) continue;
            int k = cnt[j] - i + 1;
            for (int l = 0; l < k; l++) {
                sum += b[j][l].first;
                buy[b[j][l].second] = true;
                people++;
            }
        }
        for (int p = 0; p < arr.size(); p++) {
            if (i - people <= 0) break;
            if (buy[arr[p].second]) continue;
            sum += arr[p].first;
            people++;
        }
        if (people >= i)
            ans = min(ans, sum);
        for (int j = 0; j < n; j++) buy[j] = false;
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