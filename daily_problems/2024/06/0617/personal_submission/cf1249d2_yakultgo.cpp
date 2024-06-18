#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int a[N];
void solve() {
    int n, k;
    cin >> n >> k;
    struct node {
        int l, r;
        int idx;
    };
    vector<node> seg(n);
    for (int i = 0; i < n; i++) {
        cin >> seg[i].l >> seg[i].r;
        seg[i].idx = i + 1;
        a[seg[i].l]++;
        a[seg[i].r + 1]--;
    }
    sort(seg.begin(), seg.end(), [](node &a, node &b) {
        return a.l < b.l;
    });
    auto cmp = [&](node &a1, node &a2) {
        return a1.r < a2.r;
    };
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    int j = 0;
    vector<int> ans;
    for (int i = 1; i < N; i++) {
        while (j < n && seg[j].l <= i) {
            pq.push(seg[j]);
            j++;
        }
        a[i] += a[i - 1];
        while (a[i] > k) {
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.idx);
            a[i]--;
            a[p.r + 1]++;
        }
    }
    cout << ans.size() << endl;
    for (auto &x : ans) {
        cout << x << " ";
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