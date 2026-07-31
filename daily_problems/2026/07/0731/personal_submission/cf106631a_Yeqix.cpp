#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

i64 query1(int k) {
    cout << "MUL " << k << "\n";
    cout.flush();
    i64 x;
    cin >> x;
    return x;
}

i64 query2(int k) {
    cout << "DIV " << k << "\n";
    cout.flush();

    i64 x;
    cin >> x;
    return x;
}

void print(i64 a, i64 b) {
    cout << "ANS " << a << " " << b << "\n";
    cout.flush();
}

i64 mul(i64 a, i64 b) {
    i64 ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}

void solve() {
    i64 t = query1(1);
    i64 v = t;
    vector<array<i64, 2>> fac;
    for (i64 i = 2; 1LL * i * i <= v; i++) {
        if (v % i == 0) {
            int cnt = 0;
            while (v % i == 0) {
                cnt++;
                v /= i;
            }
            fac.push_back({i, cnt});
        }
    }

    if (v > 1) {
        fac.push_back({v, 1});
    }

    i64 all = 1, a = 1;
    for (const auto& [l, r] : fac) {
        i64 res = mul(l, r);
        i64 val = query1(res);
        all *= res;
        int cnt = 0;
        while (val % l == 0) {
            cnt++;
            val /= l;
        }
        a *= mul(l, cnt - r);
    }

    i64 b = query2(all * a);

    print(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}