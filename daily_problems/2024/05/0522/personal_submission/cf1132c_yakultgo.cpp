#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> cnt(n + 1);
    vector<pair<int, int>> arr(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        arr[i] = {l, r};
        for (int j = l; j <= r; j++) cnt[j]++;
    }
    int mi = 1e6;
    vector<int> sum(n + 1);
    for (int i = 0; i < q; i++) {
        int zero = 0;
        for (int j = arr[i].first; j <= arr[i].second; j++) cnt[j]--;

        for (int j = 1; j <= n; j++) {
            sum[j] = sum[j - 1];
            if (cnt[j] == 1) sum[j]++;
            if (cnt[j] == 0) zero++;
        }
        for (int j = i + 1; j < q; j++) {
            mi = min(mi, sum[arr[j].second] - sum[arr[j].first - 1] + zero);
        }
        for (int j = arr[i].first; j <= arr[i].second; j++) cnt[j]++;
    }
    cout << n - mi << endl;
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