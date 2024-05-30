#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define aint64_t(x) (x).begin(), (x).end()
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
    int n = s.size();
    vector<int> a(n + 1, n);
    int64_t res = 0;
    per(i, n - 1, 0) {
        a[i] = a[i + 1]; 
        for (int k = 1; i + 2 * k < a[i]; k++) {
            if (s[i] == s[i + k] && s[i + k] == s[i + 2 * k]) {
                a[i] = i + 2 * k;
            }
        }
        res += n - a[i];
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
https://codeforces.com/problemset/problem/1168/B
*/

  

  

  

  

  
