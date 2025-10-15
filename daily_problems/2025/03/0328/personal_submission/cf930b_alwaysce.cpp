#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    map<char, vector<int>> mp;
    int l = s.size();

    for (int i = 0; i < l; i++) {
        mp[s[i]].emplace_back(i);
    }

    int ans = 0;
    for (auto& [k, v]: mp) {
        int res = 0;
        for (int p = 0; p < l; p++) {
            map<char,int> cnt;
            for (auto&x: v) {
                cnt[s[(x + p) % l]]++;
            }

            int cur = 0;
            for (auto& [_, c]: cnt) {
                cur += (c == 1);
            }

            res = max(res, cur);
        }
        ans += res;
    }
    cout << fixed << setprecision(10) << (long double)1.0 * ans / l;
    return 0;
}
