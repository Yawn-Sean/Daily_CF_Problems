#include <bits/stdc++.h>

using namespace std;
constexpr int MXN = 200000;
int a[MXN];
constexpr int MOD = 998244353;

int fast_pow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = 1LL * a * a % MOD) {
        if (b & 1) {
            res = 1LL * res * a % MOD;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> nxt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        nxt[a[i]] = i;
    }
    int k = 0;
    for (int i = 0, curr = 0; i < n; i++) {
        curr = max(curr, nxt[a[i]]);
        if (curr == i) {
            k++;
        }
    }
    cout << fast_pow(2, k - 1) << "\n";
    return 0;
}

