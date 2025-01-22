#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int pow2[N];

void initC() {
    pow2[0] = 1;
    for (int i = 1; i < N; ++i) {
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }
}

void solveC() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int> psum(n+1);
    for (int i = 1; i <= n; ++i) {
        psum[i] = psum[i-1] + (s[i-1] == '1');
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int a = psum[r] - psum[l-1], b = r - l + 1 - a;
        cout << 1LL * pow2[b] * (pow2[a] - 1) % MOD << '\n';
    }
}

int main() {
    initC();
    solveC();
    return 0;
}
