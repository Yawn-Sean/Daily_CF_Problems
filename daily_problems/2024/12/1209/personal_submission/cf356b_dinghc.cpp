#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    string x, y;
    cin >> x >> y;
    int a = x.length(), b = y.length();
    int g = gcd(a, b);
    vector<vector<long long>> cnt(g, vector<long long>(26, 0LL));
    for (int i = 0; i < b; i++) {
        cnt[i % g][y[i] - 'a']++;
    }
    long long d = 0LL;
    for (int i = 0; i < a; i++) {
        int xi = x[i] - 'a';
        for (int c = 0; c < 26; c++) {
            if (c != xi) {
                d += cnt[i % g][c];
            }
        }
    }
    long long ans = 1LL * a * n / lcm(static_cast<long long>(a), static_cast<long long>(b)) * d;
    cout << ans << "\n";
    return 0;
}

