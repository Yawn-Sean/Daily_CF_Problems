#include <bits/stdc++.h>
using namespace std;
#define int long long

void run_case() {
    cout << "MUL 1" << endl;
    int n; cin >> n;
    cout << "MUL " << n << endl;
    int a; cin >> a;
    a /= n;
    cout << "DIV " << a * n << endl;
    int b; cin >> b;
    cout << "ANS " << a << " " << b << endl;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run_case();
        // cout << '\n';
        // cout << endl;
    }
    return 0;
}