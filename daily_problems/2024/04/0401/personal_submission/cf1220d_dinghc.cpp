#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<long long, vector<long long>> freq;
    pair<int, long long> mx{0, 0};
    long long x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        freq[x & -x].push_back(x);
        mx = max(mx, {static_cast<int>(freq[x & -x].size()), x & -x});
    }

    cout << n - mx.first << "\n";
    for (auto& [k, v] : freq) {
        if (k != mx.second) {
            for (auto& x : v) {
                cout << x << " ";
            }
        }
    }

    return 0;
}

