#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int, int> mp;
    int block = 1e9;
    for (int i = 100000; i >= 0; i--) {
        ll val = 1;
        for (int j = 0; j <= i; j++) {
            if (val > block) {
                break;
            }
            mp[val] = i + 1;
            val = val * (i - j) / (j + 1);
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int t;
        cin >> t;
        if (mp.count(t)) {
            cout << mp[t] << "\n";
        } else {
            cout << t + 1 << "\n";
        }
    }
    return 0;
}