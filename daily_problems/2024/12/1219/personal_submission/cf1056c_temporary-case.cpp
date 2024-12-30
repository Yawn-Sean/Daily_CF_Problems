#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
const int MX = 1e3 + 5;

void solve() {
    map<int, int> mapping;
    priority_queue<pair<int, int> > pq;
    set<int> lazy;
    int n, m;
    cin >> n >> m;
    vector<int> a(n*2 + 1);
    for (int i = 1; i <= n * 2; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        mapping[x] = y;
        mapping[y] = x;
        if (a[x] > a[y]) {
            pq.push({MX, x});
            pq.push({a[y], x});
        }
        else {
            pq.push({MX, y});
            pq.push({a[x], x});
        }
    }

    for (int i=1;i<=n*2;i++) {
        if (mapping.find(i) == mapping.end()) {
            pq.push({a[i], i});
        }
    }

    int start;
    cin >> start;
    int limit = start + 2 * n;
    while (start < limit) {
        if (start % 2) {
            while (lazy.count(pq.top().second)) {
                pq.pop();
            }
            auto t = pq.top();
            pq.pop();
            lazy.insert(t.second);
            cout << t.second << endl;
        } else {
            int v;
            cin >> v;
            lazy.insert(v);
            if (mapping.find(v) != mapping.end() && !lazy.count(mapping[v])) {
                cout << mapping[v] << endl;
                lazy.insert(mapping[v]);
                start++;
            }
        }
        start++;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}
