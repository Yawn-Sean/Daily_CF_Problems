#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;

    s += "!";

    i64 ans = 0;
    vector<pair<char, i64>> f;
    char pre = s[0];
    i64 cnt = 0;
    for (const auto& v : s) {
        if (v == pre) {
            cnt++;
        } else {
            ans += cnt * cnt;
            f.push_back({pre, cnt});
            pre = v, cnt = 1;
        }
    }

    auto get = [&](i64 x) -> i64 { return x * x; };

    auto check = [&](int i, int j) -> i64 {
        i64 res = ans;
        if (f[i].second == 1) {
            res += get(f[j].second - 1) - get(f[j].second);
            if (i - 1 >= 0 && f[i - 1].first == f[j].first) {
                res += get(f[i - 1].second + 1) - get(f[i - 1].second);
            } else {
                res++;
            }
        }
        if (f[j].second == 1) {
            res += get(f[i].second - 1) - get(f[i].second);
            if (j + 1 < f.size() && f[j + 1].first == f[i].first) {
                res += get(f[j + 1].second + 1) - get(f[j + 1].second);
            } else {
                res++;
            }
        }
        if (f[j].second != 1 && f[i].second != 1) {
            res += get(f[i].second - 1) + get(f[j].second - 1) + 2 - get(f[i].second) - get(f[j].second);
        }
        return res;
    };

    i64 res = 0;
    for (int i = 1; i < f.size(); i++) {
        res = max(res, check(i - 1, i));
    }

    cout << res;
    return 0;
}