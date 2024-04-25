#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
set<int> st[N];
int cnt = 0;
pair<int, int> arr[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        st[a].insert(b);
    }
    for (int i = 1; i <= n; i++) {
        if (st[i].empty()) continue;
        arr[++cnt] = {*st[i].rbegin(), i};
    }
    sort(arr + 1, arr + cnt + 1, [](auto &a, auto &b) {
        return a.first > b.first;
    });
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        set<int> tmp;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            if (st[x].empty()) continue;
            tmp.insert(x);
        }
        if (cnt == tmp.size()) {
            cout << "0 0" << endl;
            continue;
        }
        int fid = 0, sid = 0;
        for (int i = 1; i <= cnt; i++) {
            if (!tmp.count(arr[i].second)) {
                if (cnt - 1 == tmp.size()) {
                    cout << arr[i].second << " " << *st[arr[i].second].begin() << endl;
                    break;
                }
                if (fid == 0) {
                    fid = arr[i].second;
                } else {
                    sid = arr[i].second;
                    break;
                }
            }
        }
        if (fid == 0 && sid == 0) continue;
        int mx = *st[sid].rbegin();
        // 在fid里面找到第一个大于mx的
        auto it = st[fid].upper_bound(mx);
        cout << fid << " " << *it << endl;
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