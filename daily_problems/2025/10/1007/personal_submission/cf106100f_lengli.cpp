#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, long long val) {
        idx++; 
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    long long sum(int r) {  
        long long res = 0;
        while (r > 0) {
            res += bit[r];
            r -= r & -r;
        }
        return res;
    }

    long long sum(int l, int r) { 
        return sum(r) - sum(l);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    for (int i = 0; i < n; i++) {
        a[i] -= i;
        b[i] -= i;
    }

    map<int, vector<int>> pos_map;
    for (int i = 0; i < n; i++) {
        pos_map[a[i]].push_back(i);
    }

    for (int i = n - 1; i >= 0; i--) {
        auto it = pos_map.find(b[i]);
        if (it == pos_map.end() || it->second.empty()) {
            cout << -1 << '\n';
            return 0;
        }
        b[i] = it->second.back();
        it->second.pop_back();
    }

    Fenwick fen(n);
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans += fen.sum(b[i], n);
        fen.add(b[i], 1);
    }

    cout << ans << '\n';
    return 0;
}
