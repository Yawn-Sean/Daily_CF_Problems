#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

int inline red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red();
    string sa, sb;
    cin >> sa >> sb;
    vector<int> a(n), b(n);
    rep(i, 0, n) {
        a[i] = (int)(sa[i] - '0');
        b[i] = (int)(sb[i] - '0');
    }
    int res = 1e9, s0 = 0, s1 = 0, uns0 = 0, uns1 = 0;
    rep(i, 0, n) {
        if (a[i] != b[i]) {
            if (a[i]) {
                uns1++;
            } else {
                uns0++;
            }
        } else {
            if (a[i]) {
                s1++;
            } else {
                s0++;
            }
        }
    }
    if (uns0 == uns1) {
        res = min(res, uns0 + uns1);
    }
    if (s1) {
        s1--;
        if (s1 == s0) {
            res = min(res, s0 + s1 + 1);
        }
    }
    cout << (res == 1e9 ? -1 : res) << '\n';
}
  
int main() {  
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = red();
    while (t--) {  
        solve();
    }  
    return 0;  
}

/*
https://codeforces.com/problemset/problem/1615/C
*/