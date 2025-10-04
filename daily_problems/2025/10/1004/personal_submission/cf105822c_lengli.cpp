#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        int parity = 0;
        for (char c : s) if (c == 'E') parity ^= 1;

        if (parity) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        int p1 = 1, p2 = 2;
        for (char c : s) {
            if (c == 'O') {
                cout << p1 << ' ' << p2 << '\n';
                p1 += 2;
                p2 += 2;
            } else { 
                if (p1 < p2) {
                    cout << p1 << ' ' << p1 + 2 << '\n';
                    p1 += 4;
                } else {
                    cout << p2 << ' ' << p2 + 2 << '\n';
                    p2 += 4;
                }
            }
        }
    }
    return 0;
}
