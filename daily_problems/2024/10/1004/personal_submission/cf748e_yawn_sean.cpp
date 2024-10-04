#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int M = 1e7;
    vector<long long> cnt(M + 1, 0);

    while (n --) {
        int x;
        cin >> x;
        cnt[x] ++;
    }

    long long cur = 0;

    for (int i = M; i > 0; i --) {
        cur += cnt[i];

        if (i * 2 + 1 <= M) {
            cur += cnt[i * 2 + 1];
            cnt[i] += cnt[i * 2 + 1];
            cnt[i + 1] += cnt[i * 2 + 1];
        }

        if (i * 2 <= M) {
            cur += cnt[i * 2];
            cnt[i] += cnt[i * 2] * 2;
        }

        if (cur >= k) return cout << i, 0;
    }
    
    cout << -1;

    return 0;
}