#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

void solveC() {
    int n, x, ans = 0;
    cin >> n;
    vector<int> pxor(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        ans ^= x;
        pxor[i] = pxor[i-1] ^ i;
    }
    for (int i = 1; i <= n; i++) {
        int t = n % (2 * i);
        if (t >= i) ans ^= pxor[i-1] ^ pxor[t-i];
        else ans ^= pxor[t];
    }
    cout << ans << endl;
}

int main() {
    solveC();
}
