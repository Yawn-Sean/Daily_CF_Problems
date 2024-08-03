#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pi pair<int, int>
#define all(x) (x).begin(), (x).end()

inline int red() {
    int x;
    cin >> x;
    return x;
}

inline int red1() {
    int x;
    cin >> x;
    return --x;
}

void solve() {
    int n = red(), k = red(), i, j;
    string s;
    cin >> s;

    vector<int> l(k), r(k);
    generate(all(l), red1);
    generate(all(r), red1);

    int q;
    cin >> q;

    vector<int> f(n);

    while (q--) {
        int x = red1();
        f[x] ^= 1;
    }

    for (i = 0; i < k; i++) {
        int rev = 0;
        for (j = l[i]; j <= l[i] + r[i] - j; j++) {
            rev ^= f[j] ^ f[l[i] + r[i] - j];
            if (rev) {
                swap(s[j], s[l[i] + r[i] - j]);
            }
        }
    }

    cout << s << '\n';
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

