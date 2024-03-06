#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        bool ans = false;
        if (k % 3 == 0) {
            int p = n % (k + 1);
            ans = p == k || p % 3 != 0;
        } else {
            ans = n % 3 != 0;
        }

        cout << (ans ? "Alice" : "Bob") << "\n";
    }
    return 0;
}