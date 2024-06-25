#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    string s;
    cin >> s;
    int i, j, res = 0, n = s.size();
    for (i = 0; i < n; i++) {
        int cnt = 0, val = 0;
        for (j = i; j < n; j++) {
            if (s[j] == '(') {
                cnt++;
            } else if (s[j] == ')') {
                cnt--;
            } else {
                cnt--;
                val++;
            }   
            if (cnt == -1) {
                if (!val) {
                    break;
                } else {
                    val--;
                    cnt += 2;
                }
            } else if (!cnt) {
                res++;
            }
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    } 

    return 0;
}

/*
https://codeforces.com/problemset/problem/917/A
*/