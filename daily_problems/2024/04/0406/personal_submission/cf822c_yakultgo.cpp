#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
struct node {
    int l, r, cost;
};
vector<node> v[N];
void solve() {
    int n, m;
    cin >> n >> m;
    vector<node> arr(n);
    for (int i = 0; i < n; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        arr[i] = {l, r, c};
        v[r - l + 1].push_back({l, r, c});
    }
    int ans = INT_MAX;
    sort(arr.begin(), arr.end(), [&](node a, node b) {
        return a.l < b.l;
    });
    for (int i = 1; i <= 2e5; i++) {
        sort(v[i].begin(), v[i].end(), [&](node a, node b) {
            return a.l < b.l;
        });
        for (int j = v[i].size() - 2; j >= 0; j--) {
            v[i][j].cost = min(v[i][j].cost, v[i][j + 1].cost);
        }
    }
    for (int i = 0; i < n; i++) {
        int l = arr[i].l, r = arr[i].r, c = arr[i].cost;
        if (r - l + 1 >= m) continue;
        int need = m - (r - l + 1);
        int left = 0, right = v[need].size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (v[need][mid].l > r)
                right = mid;
            else
                left = mid + 1;
        }
        if (left < v[need].size())
            ans = min(ans, c + v[need][left].cost);
    }
    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
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