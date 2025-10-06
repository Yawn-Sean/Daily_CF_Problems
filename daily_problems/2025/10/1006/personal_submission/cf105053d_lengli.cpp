#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N;
    if (!(cin >> N)) return 0;

    if (N == 1) { cout << "N\n"; return 0; }

    vector<pair<long long,int>> fac;
    long long n = N;

    int cnt = 0;
    while (n % 2 == 0) { n /= 2; cnt++; }
    if (cnt) fac.push_back({2, cnt});

    for (long long d = 3; d * d <= n; d += 2) {
        if (n % d == 0) {
            int c = 0;
            while (n % d == 0) { n /= d; c++; }
            fac.push_back({d, c});
        }
    }
    if (n > 1) fac.push_back({n, 1});

    if (fac.size() == 1) {
        cout << (fac[0].second % 2 == 1 ? "Y\n" : "N\n");
    } else if (fac.size() == 2 && fac[0].second == 1 && fac[1].second == 1) {
        // N = p*q
        cout << "Y\n";
    } else {
        cout << "N\n";
    }
    return 0;
}
