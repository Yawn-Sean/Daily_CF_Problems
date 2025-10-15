#include<bits/stdc++.h>

using namespace std;
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
