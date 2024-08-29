#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;
using i64 = long long;

inline int read() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = read();
    int all_zero = 0, all_one = 1023, cur;
    char c;
    while (n--) {
        cin >> c >> cur;
        if (c == '|') {
            all_zero |= cur;
            all_one |= cur;
        } else if (c == '&') {
            all_zero &= cur;
            all_one &= cur;
        } else {
            all_zero ^= cur;
            all_one ^= cur;
        }
    }
    ve<int> a(10), b(10);
    int idx = 0;
    while (all_zero) {
        a[idx++] = all_zero % 2;
        all_zero >>= 1;
    }   
    idx = 0;
    while (all_one) {
        b[idx++] = all_one % 2;
        all_one >>= 1;
    }   

    ve<int> yu(10, 1);
    int aa = 0, bb = 0, cc = 0, res = 0;
    bool fa = false, fb = false, fc = false;
    rep(i, 0, 10) {
        if (!a[i] && !b[i]) {
            if (!fa) {
                fa = true;
                res++;
            }
            yu[i] = 0;
        } else if (a[i] == 1 && b[i] == 1) {
            if (!fb) {
                fb = true;
                res++;
            }
            bb += 1 << i;
        } else if (a[i] == 1 && !b[i]) {
            if (!fc) {
                fc = true;
                res++;
            }
            cc += 1 << i;
        } 
    }
    rep(i, 0, 10) {
        if (yu[i]) {
            aa += 1 << i;
        }
    }
    cout << res << '\n';
    if (fa) {
        cout << '&' << ' ' << aa << '\n'; 
    }
    if (fb) {
        cout << '|' << ' ' << bb << '\n';  
    }
    if (fc) {
        cout << '^' << ' ' << cc << '\n';
    }
     
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}