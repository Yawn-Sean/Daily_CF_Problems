#include <bits/stdc++.h>
using namespace std;

static vector<int> prefix(const string &s) {
    int n = (int)s.size();
    vector<int> p(n);
    for (int i = 1, j = 0; i < n; ++i) {
        while (j && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) ++j;
        p[i] = j;
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    int need;
    getline(cin, s);
    getline(cin, t);
    cin >> need;

    int m = (int)t.size();
    int L = 1, R = m, best = 0;

    auto ok = [&](int len) {
        string u;
        u.reserve(len + 1 + s.size());
        u.append(t, 0, len).push_back('#');
        u += s;
        auto p = prefix(u);
        int cnt = 0;
        for (int v : p) cnt += (v == len);
        return cnt >= need;
    };

    while (L <= R) {
        int mid = (L + R) >> 1;
        if (ok(mid)) best = mid, L = mid + 1;
        else R = mid - 1;
    }

    if (best) cout << t.substr(0, best);
    else cout << "IMPOSSIBLE";
    return 0;
}
