/*
 https://codeforces.com/problemset/problem/631/D
 D. Messenger
 Solver: nhant
 2025-05-02 18:44:10
 https://codeforces.com/problemset/submission/631/318096707, 62 ms, 5000 KB
*/
#include <bits/stdc++.h>

using namespace std;

int parse(vector<char>& s, vector<int64_t>& cnt) {
    int len = 0;
    for (int i = 0, n = (int) s.size(); i < n; i++) {
        string x;
        cin >> x;
        int cc = 0;
        for (char c : x) {
            if ('0' <= c && c <= '9') {
                cc = cc * 10 + (c - '0');
            }
        }
        char ch = x[(int)x.size() - 1];
        if (len > 0 && s[len - 1] == ch) {
            cnt[len - 1] += cc;
        } else {
            s[len] = ch;
            cnt[len] = cc;
            len++;
        }
    }
    return len;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<char> s(n), t(m);
    vector<int64_t> sc(n), tc(m);
    int sl = parse(s, sc);
    int tl = parse(t, tc);
    int64_t res = 0;
    if (tl == 1) {
        for (int i = 0; i < sl; i++) {
            if (s[i] == t[0] && sc[i] >= tc[0]) {
                res += sc[i] - tc[0] + 1;
            }
        }
    } else if (tl == 2) {
        for (int i = 0; i < sl - 1; i++) {
            if (s[i] == t[0] && sc[i] >= tc[0] && s[i + 1] == t[1] && sc[i + 1] >= tc[1]) {
                res++;
            }
        }
    } else {
        int nu = tl - 1 + sl;
        vector<char> u(nu);
        vector<int64_t> uc(nu);
        for (int i = 1; i < tl - 1; i++) {
            u[i - 1] = t[i];
            uc[i - 1] = tc[i];
        }
        u[tl - 2] = '#';
        for (int i = 0; i < sl; i++) {
            u[tl - 1 + i] = s[i];
            uc[tl - 1 + i] = sc[i];
        }
        vector<int> p(nu);
        for (int i = 1; i < nu; i++) {
            int j = p[i - 1];
            while (j > 0 && (u[j] != u[i] || uc[j] != uc[i])) {
                j = p[j - 1];
            }
            if (u[j] == u[i] && uc[j] == uc[i]) {
                j++;
            }
            p[i] = j;
            if (j == tl - 2) {
                int fi = i - (tl - 2), la = i + 1;
                if (u[fi] == t[0] && uc[fi] >= tc[0] && u[la] == t[tl - 1] && uc[la] >= tc[tl - 1]) {
                    res++;
                }
            }
        }
    }
    cout << res << '\n';
}
