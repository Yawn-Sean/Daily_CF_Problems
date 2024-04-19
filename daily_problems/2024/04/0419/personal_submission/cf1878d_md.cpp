#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    std::cin >> n >> k;
    string s;
    cin >> s;

    vector<int> l(k), r(k);
    for (auto& lv : l) {
        cin >> lv;
        --lv;
    }

    for (auto& rv : r) {
        cin >> rv;
        --rv;
    }

    int q;
    cin >> q;
    vector<int> cnt(n);
    while (q--) {
        int x;
        cin >> x;
        cnt[--x]++;
    }

    for (int i = 0; i < k; ++i) {
        int sum = 0;
        for (int j = l[i]; j <= r[i] + l[i] - j; ++j) {
            sum += cnt[j] + cnt[r[i] + l[i] - j];
            if (sum & 1) {
                swap(s[j], s[r[i] + l[i] - j]);
            }
        }
    }

    cout << s << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}