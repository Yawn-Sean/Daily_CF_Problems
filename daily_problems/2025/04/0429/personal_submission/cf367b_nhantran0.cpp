/**
 * https://codeforces.com/problemset/problem/367/B
 * B. Sereja ans Anagrams
 * Solver: nhant
 * 2025-04-30 01:02:44
 * https://codeforces.com/problemset/submission/367/317768518, 421 ms, 16100 KB
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    map<int,int> fb, fa;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        fb[b]++;
    }
    int res = 0;
    vector<bool> pok(n);
    for (int i = 0; i < p; i++) {
        fa.clear();
        int len = 0, match = 0;
        for (int j = i; j < n; j += p) {
            if (fb.find(a[j]) == fb.end()) {
                fa.clear();
                len = 0;
                match = 0;
                continue;
            }
            len++;
            int acnt = ++fa[a[j]];
            int bcnt = fb[a[j]];
            if (acnt == bcnt) {
                match++;
            }
            if (len > m) {
                int l = j - m * p;
                acnt = --fa[a[l]];
                bcnt = fb[a[l]];
                if (acnt == bcnt - 1) {
                    match--;
                }
            }
            if (match == (int)fb.size()) {
                res++;
                pok[j-(m-1)*p] = true;
            }
        }
    }
    cout << res << '\n';
    if (res > 0) {
        for (int i = 0; i < n; i++) if (pok[i]) cout << (i + 1) << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
