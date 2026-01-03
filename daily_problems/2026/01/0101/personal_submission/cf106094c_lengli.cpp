#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int M = 200000;
    vector<int> pr(M + 1);
    for (int i = 0; i <= M; i++) pr[i] = i;

    for (int i = 2; i <= M; i++) {
        if (pr[i] == i) {
            for (int j = i; j <= M; j += i) {
                pr[j] = i;
            }
        }
    }

    int t;
    cin >> t;
    vector<long long> outs;
    outs.reserve(t);

    while (t--) {
        long long x, k;
        cin >> x >> k;

        vector<long long> cnt;
        while (x > 1) {
            int p = pr[x];
            long long c = 0;
            while (x % p == 0) {
                x /= p;
                c++;
            }
            cnt.push_back(c);
        }

        long long ans = 0;
        long long cur = 2;
        long long v = 1;

        while (true) {
            long long tmp = 0;
            for (size_t i = 0; i < cnt.size(); i++) {
                long long val = (cnt[i] + cur - 1) / cur;
                tmp += val * cur - cnt[i];
                cnt[i] = val * cur;
            }

            if (tmp > k) break;

            ans = v;
            k -= tmp;
            cur *= 2;
            v += 1;
        }

        outs.push_back(ans);
    }

    for (auto x : outs) {
        cout << x << '\n';
    }

    return 0;
}
