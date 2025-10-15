#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int MOD = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<string> vs, mx;
    string s;
    for (int i = 0; i < 2 * n - 2; ++i) {
        cin >> s;
        vs.emplace_back(s);
        if (s.length() == n-1) {
            mx.emplace_back(s);
        }
    }
    string pre = mx[0], suf = mx[1];
    string s1 = pre + suf.back(), s2 = suf + pre.back();

    auto check = [&](string tmp) {
        string res;
        multiset<string> pres, sufs;
        for (int i = 1; i < n; ++ i) {
            pres.insert(tmp.substr(0, i));
            sufs.insert(tmp.substr(n-i));
        }
        for (auto& s : vs) {
            if (pres.contains(s)) {
                res += "P";
                pres.erase(pres.find(s));
            } else if (sufs.contains(s)) {
                res += "S";
                sufs.erase(sufs.find(s));
            } else {
                return string("");
            }
        }
        return res;
    };

    string ans1 = check(s1), ans2 = check(s2);
    cout << (ans1.empty() ? ans2 : ans1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}