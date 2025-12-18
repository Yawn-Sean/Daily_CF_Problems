#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long p, h;
    cin >> n >> p >> h;

    vector<long long> muls, adds;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        if (op == '*') {
            long long x;
            cin >> x;
            if (x > 1) muls.push_back(x);
        } else if (op == '+') {
            long long x;
            cin >> x;
            adds.push_back(x);
        } else {
            cnt++;
        }
    }

    sort(muls.begin(), muls.end(), greater<long long>());
    sort(adds.begin(), adds.end(), greater<long long>());

    if (cnt == 0) {
        cout << "*\n";
        return 0;
    }

    if (muls.empty() && adds.empty()) {
        if (p == 0) {
            cout << "*\n";
        } else {
            h = (h - 1) / p + 1;
            long long rounds = (h - 1) / cnt;
            cout << rounds * n + h - rounds * cnt << "\n";
        }
        return 0;
    }

    const long long INF = 1000000000LL;
    long long ans = 0;

    while (true) {
        long long cur = p;

        for (long long x : adds) {
            cur = min(cur + x, INF);
        }
        for (long long x : muls) {
            cur = min(cur * x, INF);
        }

        if (cur * cnt < h) {
            h -= cur * cnt;
            ans += n;
            p = cur;
        } else {
            long long res = n;

            long long cur_add = p;
            for (int i = 0; i <= (int)adds.size(); i++) {
                if (i > 0) {
                    cur_add = min(cur_add + adds[i - 1], INF);
                }

                long long cur_mul = cur_add;
                for (int j = 0; j <= (int)muls.size(); j++) {
                    if (j > 0) {
                        cur_mul = min(cur_mul * muls[j - 1], INF);
                    }

                    for (int k = 0; k <= cnt; k++) {
                        if (cur_mul * k >= h) {
                            res = min(res, (long long)i + j + k);
                        }
                    }
                }
            }

            ans += res;
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}
