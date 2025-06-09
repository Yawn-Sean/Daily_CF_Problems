#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
i64 mod = 1e9 + 7;
int inf = 1e9;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    cin >> n;

    map<pair<int,string>, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        string s, t;
        cin >> s >> t;

        int mask = 0;
        for (auto&ch: t) {
            mask |= (1 << (ch - 'a'));
        }

        int idx = s.size() - 1;
        while (idx >= 0 && (mask >> (s[idx] - 'a') & 1)) {
            --idx;
        }

        s = s.substr(0, idx + 1);
        mp[{mask, s}].emplace_back(i);
    }

    cout << mp.size() << '\n';
    for (auto&[k, v]: mp) {
        cout << v.size() << ' ';
        for (auto&x: v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
	return 0;
}

