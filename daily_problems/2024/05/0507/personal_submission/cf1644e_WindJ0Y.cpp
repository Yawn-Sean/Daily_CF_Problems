#include <bits/stdc++.h>
using namespace std;

void work() {
    int n; cin >> n;
    string s; cin >> s;

    int cpos = -1;
    for (int i = 0; i < s.size(); i ++) {
        if (s[0] != s[i]) {
            cpos = i;
            break;
        }
    }

    if (cpos == -1) {
        cout << n << "\n";
    } else {
        int acnt = 0;
        int bcnt = 0;
        for (int i = cpos; i < s.size(); i ++) {
            if (s[i] == 'D') {
                acnt ++;
            } else {
                bcnt ++;
            }
        }
        long long ans = cpos + 1ll * (n - cpos) * n - 1ll * acnt * bcnt;
        cout << ans << "\n"; 
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    cin >> T;

    while (T--) {
        work();
    }
}