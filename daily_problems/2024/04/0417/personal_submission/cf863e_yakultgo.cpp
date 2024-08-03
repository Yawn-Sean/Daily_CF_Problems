#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

const int M = 6e5 + 10;
int diff[M];
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    set<int> s;
    map<int, int> rank;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        s.insert(a[i].first);
        s.insert(a[i].second);
        s.insert(a[i].second + 1);
    }
    int cnt = 0;
    for (int x : s) {
        rank[x] = ++cnt;
    }
    for (int i = 0; i < n; i++) {
        a[i].first = rank[a[i].first];
        a[i].second = rank[a[i].second];
        diff[a[i].first]++;
        diff[a[i].second + 1]--;
    }
    for (int i = 1; i <= cnt; i++) {
        diff[i] += diff[i - 1];
    }
    buildMin(1, 1, cnt);
    for (int i = 0; i < n; i++) {
        int mi = queryMin(1, a[i].first, a[i].second);
        if (mi > 1) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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