#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int inf = 2e9 + 1;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> pos(k);
    vector<int> temp(k);
    for (int i = 0; i < k; i++) {
        cin >> pos[i];
    }

    for (int i = 0; i < k; ++i) {
        cin >> temp[i];
    }

    map<int, int> condmap;
    for (int i = 0; i < k; ++i) {
        condmap[pos[i]] = temp[i];
    }

    vector<int> ret(n, inf);
    int minval = inf;
    for (int i = 1; i <= n; ++i) {
        if (condmap.contains(i)) {
            minval = min(minval, condmap[i]);
        }
        ret[i - 1] = minval;
        minval++;
    }

    minval = inf;
    for (int i = n; i >= 1; --i) {
        if (condmap.contains(i)) {
            minval = min(minval, condmap[i]);
        }

        ret[i - 1] = min(ret[i - 1], minval);
        minval++;
    }

    for (int i = 0; i < n; ++i) {
        cout << ret[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        string empty_line;
        getline(std::cin, empty_line);
        solve();
    }

    return 0;
}