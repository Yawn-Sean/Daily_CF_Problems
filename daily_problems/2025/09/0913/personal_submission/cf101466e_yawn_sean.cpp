#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

vector<int> prep(string s) {
    int n = s.size();
    vector<int> pi(n, 0);

    int j = 0;
    for (int i = 1; i < n; i ++) {
        while (j && s[j] != s[i]) j = pi[j - 1];
        if (s[j] == s[i]) j ++;
        pi[i] = j;
    }

    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    int cur;

    getline(cin, s);
    getline(cin, t);
    cin >> cur;

    int n = s.size(), m = t.size();

    int l = 1, r = m;
    while (l <= r) {
        int mid = (l + r) / 2;

        string tmp = t.substr(0, mid) + "#" + s;
        auto kmp = prep(tmp);

        int cnt = 0;
        for (auto &v: kmp) cnt += (v == mid);

        if (cnt >= cur) l = mid + 1;
        else r = mid - 1;
    }

    if (r) cout << t.substr(0, r);
    else cout << "IMPOSSIBLE";

    return 0;
}