#include <bits/stdc++.h>
using namespace std;

void work() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    int sp = 0;
    int ep = n - 1;
    while (s[sp] == t[sp]) {
        sp ++;
    }
    while (s[ep] == t[ep]) {
        ep --;
    }
    assert(sp <= ep);

    int ans = 2;
    for (int i = sp + 1; i <= ep; i++) {
        if (s[i] != t[i - 1]) {
            ans --;
            break;
        }
    }
    for (int i = sp + 1; i <= ep; i++) {
        if (t[i] != s[i - 1]) {
            ans --;
            break;
        }
    }

    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}