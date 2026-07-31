#include <bits/stdc++.h>
using namespace std;
#define int long long

void run_case() {
    int n; cin >> n;
    string s; cin >> s;

    bool op = true;
    for (int i = 0; i < n-2; i++) {
        if (s[i] != s[i+1]) op = false;
    }

    if (n >= 3 && !op) {
        cout << "Alice";
        return;
    }
    cout << "Bob";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run_case();
        cout << '\n';
    }
    return 0;
}