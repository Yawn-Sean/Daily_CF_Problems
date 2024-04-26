#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, b;
    cin >> n >> b;

    int rb = sqrt(b);
    vector<pair<long long, long long>> divisors;
    for (int i = 2; i <= rb; i++) {
        if (b % i == 0) {
            long long cnt = 0LL;
            do {
                b /= i;
                cnt++;
            } while (b % i == 0);
            divisors.emplace_back(i, cnt);
        }
    }
    if (b > 1) divisors.emplace_back(b, 1LL);

    long long ans = LONG_LONG_MAX;
    for (auto& [p, cnt_b] : divisors) {
        long long q = n;
        long long cnt = 0LL;
        while (q) {
            cnt += q / p;
            q /= p;
        }
        ans = min(ans, cnt / cnt_b);
    }

    cout << ans << "\n";


    return 0;
}

