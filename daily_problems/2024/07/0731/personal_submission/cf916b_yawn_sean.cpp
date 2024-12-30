#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int popcount(long long x) {
    int cnt = 0;
    while (x)
        x -= x & -x, cnt ++;
    return cnt;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    int k;
    cin >> n >> k;

    if (popcount(n) > k) {
        cout << "No";
        return 0;
    }

    vector<int> ans;

    if (n < k) {
        int v = 63 - __builtin_clzll(k / n);
        for (int i = 0; i < n << v; i ++) 
            ans.push_back(-v);
    }
    else {
        int l = 0, r = 63 - __builtin_clzll(n);
        while (l <= r) {
            int m = (l + r) / 2;
            long long cur = n, cnt = 0;
            for (int i = m; i >= 0; i --) {
                long long v = cur >> i;
                cnt += v;
                cur -= v << i;
            }
            if (cnt <= k) r = m - 1;
            else l = m + 1;
        }
        for (int i = l; i >= 0; i --) {
            long long v = n >> i;
            n -= v << i;
            for (int _ = 0; _ < v; _ ++) 
                ans.emplace_back(i);
        }
    }

    while (ans.size() < k) {
        int u = ans.back();
        ans.pop_back();
        ans.emplace_back(u - 1);
        ans.emplace_back(u - 1);
    }
    cout << "Yes\n";
    for (auto x: ans)
        cout << x << ' ';

    return 0;
}