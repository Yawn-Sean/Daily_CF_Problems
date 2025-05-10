/*
 https://codeforces.com/problemset/problem/689/B
 B. Mike and Shortcuts
 Solver: nhant
 2025-05-10 18:43:38
 https://codeforces.com/problemset/submission/689/319050091
*/
#include <bits/stdc++.h>

using namespace std;

void solve() {
    array<int, 2> dirs = {-1, 1};
    const int MAX_ENERGY = (int)1e9;
    int n;
    cin >> n;
    vector<int> a(n + 1), en(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        en[i] = MAX_ENERGY;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(1);
    en[1] = 0;
    while (q.size() > 0) {
        int u = q.top();
        q.pop();
        if (a[u] != u && en[a[u]] > en[u] + 1) {
            en[a[u]] = en[u] + 1;
            q.push(a[u]);
        }
        for (int d : dirs) {
            int v = u + d;
            if (v >= 1 && v <= n && en[v] > en[u] + 1) {
                en[v] = en[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << en[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
