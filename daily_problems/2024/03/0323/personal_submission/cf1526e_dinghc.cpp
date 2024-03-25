#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
constexpr i64 MOD = 998'244'353LL;

constexpr int MXN = 400005;
i64 factorials[MXN]{1};

int fast_pow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = 1LL * a * a % MOD) {
        if (b & 1) {
            res = 1LL * res * a % MOD;
        }
    }
    return res;
}

i64 fact(int m) {
    if (factorials[m]) return factorials[m];
    return factorials[m] = m * fact(m - 1) % MOD;
}

i64 inv(int a) {
    return a <= 1 ? a : fast_pow(a, MOD - 2);
}

i64 comb(int n, int k) {
    k = min(n - k, k);
    if (k == 0) return 1;
    return (fact(n) * inv(fact(k)) % MOD) * inv(fact(n - k)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> s(n);
    for (auto& si : s) {
        cin >> si;
    }
    
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[s[i]] = i;
    }

    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        int v1 = s[i] + 1;
        int v2 = s[i + 1] + 1;
        if (v1 < n && (v2 == n || pos[v1] > pos[v2])) {
            cnt++;
        }
    }
    
    int m = n - 1 - cnt + k;
    if (m < n) {
        cout << "0\n";
    } else {
        cout << comb(m, n) << "\n";
    }

    return 0;
}

