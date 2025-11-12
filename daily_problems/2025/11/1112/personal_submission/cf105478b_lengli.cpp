#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    vector<long long> outs;
    outs.reserve(t);

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        long long ans = 0;
        int flg = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] != '?') {
                ans += 1;
                ans += flg;
                flg = 0;
            } else if (i > 0 && s[i - 1] != '?') {
                if (i + 1 < n && s[i + 1] != '?' && s[i - 1] != s[i + 1]) {
                    ans += 1;
                } else if (i + 1 < n && s[i + 1] == '?') {
                    flg = 1;
                }
            }
        }

        outs.push_back(ans);
    }

    for (auto v : outs) cout << v << '\n';
    return 0;
}
