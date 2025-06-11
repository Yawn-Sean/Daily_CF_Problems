#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

const int N = 1e5 + 7;
int q[N];

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red();
    ve<int> a(n);
    generate(all(a), red);
    per(k, 30, 0) {
        int x = (1 << k), y = x - 1, res = 0;
        rep(i, 0, n) {
            if (a[i] & x) {
                y &= a[i];
                q[res++] = a[i];
            }
        }
        if (!y) {
            cout << res << '\n';
            rep(i, 0, res) {
                cout << q[i] << " \n"[i == res - 1];
            }
            break;
        }
    }
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

