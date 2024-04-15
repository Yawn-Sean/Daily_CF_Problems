#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
struct node {
    ll cost;
    ll value;
    int row;
};
void solve() {
    ll x;
    int k;
    cin >> x >> k;
    auto cmp = [](node& a, node& b) {
        return a.cost < b.cost;
    };
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        vector<int> b(n);
        ll cost = 0;
        ll value = 0;
        for (int j = 0; j < n; j++) {
            cin >> b[j];
            value += b[j];
            cost = min(cost, value);
            pq.push({cost, value, i});
        }
    }
    map<int, ll> com;
    while (!pq.empty()) {
        auto [cost, value, row] = pq.top();
        pq.pop();
        ll tmp = com[row];
        if (value - tmp <= 0) continue;
        if (x + cost < 0) continue;
        x += value - tmp;
        com[row] = value;
    }
    cout << x << endl;
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