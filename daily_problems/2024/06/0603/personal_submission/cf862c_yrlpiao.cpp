#include <iostream>
using namespace std;

void yrlpSolve() {
    int n, x; cin >> n >> x;
    if (n == 1) {
        cout << "YES" << endl;
        cout << x << endl;
    } else if (n == 2) {
        if (x != 0) cout << "YES\n" << "0 " << x << endl;
        else cout << "NO" << endl;
    } else {
        int p = 0;
        for (int i = 1; i < n; i++) {
            p ^= i;
        }
        cout << "YES" << endl;
        if ((p ^ x) == 0 || (p ^ x) >= n) {
            for (int i = 1; i < n; i++) {
                cout << i << " ";
            }
            cout << (p ^ x) << endl;
        } else {
            for (int i = 3; i < n; i++) {
                cout << i << " ";
            }
            cout << (1 << 17) + (p ^ x) << " ";
            if ((p ^ x) == 1) cout << 1 << " " << (1 << 17) + 2 << endl; 
            else cout << (1 << 17) + 1 << " " << 2 << endl;
        }
    }
    return; 
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
