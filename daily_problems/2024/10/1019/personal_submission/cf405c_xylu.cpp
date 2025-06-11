#include <bits/stdc++.h>
using namespace std;

void solveC() {
    int n, x, ans = 0, q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (i == j) ans ^= x;
        }
    }

    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 3) {
            cout << ans;
        } else {
            cin >> x;
            ans ^= 1;
        }
    }
}

int main() {
    solveC();
}
