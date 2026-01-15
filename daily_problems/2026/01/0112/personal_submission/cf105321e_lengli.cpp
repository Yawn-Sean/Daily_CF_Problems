#include <bits/stdc++.h>
using namespace std;

struct Weapon {
    int a, b, c;
};

bool cmp(const Weapon &x, const Weapon &y) {
    return 1LL * x.a * y.b + x.b < 1LL * y.a * x.b + y.b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    vector<Weapon> weapons(n);
    for (int i = 0; i < n; i++) {
        cin >> weapons[i].a >> weapons[i].b >> weapons[i].c;
    }

    sort(weapons.begin(), weapons.end(), cmp);

    vector<long long> dp(p + 1, 0);

    for (const auto &w : weapons) {
        int a = w.a, b = w.b, c = w.c;

        for (int i = b; i <= p; i++) {
            int to = (i - b) / a;
            dp[to] = max(dp[to], dp[i] + c);
        }
    }

    long long ans = 0;
    for (long long v : dp) ans = max(ans, v);

    cout << ans << '\n';
    return 0;
}
