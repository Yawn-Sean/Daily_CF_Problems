#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
const int N = 1e5 + 7;


inline int red() {
    int x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = red(), i, j, k, cnt;
    vector<int> a(n);
    vector<int> vis(N), res(N);
    generate(all(a), red);
    sort(all(a));
    int mx = a[n - 1];

    for (i = 0; i < n; ++i) {
        cnt = 1;
        for (j = a[i] << 1; j <= mx; j <<= 1) {
            vis[j]++;
            res[j] += cnt;
            ++cnt;
        }
        cnt = 0;
        for (j = a[i]; j >= 1; j >>= 1) {
            vis[j]++;
            res[j] += cnt;
            ++cnt;
            if (j & 1 && j != 1) {
                int cur = cnt + 1;
                for (k = j - 1; k <= mx; k <<= 1) {
                    vis[k]++;
                    res[k] += cur;
                    ++cur;
                }
            }
        }
    }

    int ans = 0x3f3f3f3f;
    for (i = 1; i <= mx; ++i) {
        if (vis[i] == n) {
            ans = min(ans, res[i]);
        }
    }

    cout << ans << '\n';
    return 0;
}

/*
https://codeforces.com/problemset/problem/558/C
*/