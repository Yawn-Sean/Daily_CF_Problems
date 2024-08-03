#include <bits/stdc++.h>
using namespace std;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<int> v1(n), v2(n), types(m), costs(m);

    for (int i = 0; i < n; i++)
        cin >> v1[i];

    for (int i = 0; i < n; i++)
        cin >> v2[i];

    for (int i = 0; i < m; i++)
        cin >> types[i] >> costs[i];

    vector<long long> value(m);

    int l = 1, r = n;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int c1 = v1[0], c2 = v2[0];
        for (int i = 0; i < mid; i++)
            c1 = min(c1, v1[i]), c2 = min(c2, v2[i]);

        for (int i = 0; i < m; i++)
            value[i] = (types[i] == 1 ? 1ll * costs[i] * c1 : 1ll * costs[i] * c2);

        nth_element(value.begin(), value.begin() + k - 1, value.end());
        long long tot = 0;
        for (int i = 0; i < k; i++)
            tot += value[i];

        if (tot <= s)
            r = mid - 1;
        else
            l = mid + 1;
    }
    if (l <= n)
    {
        cout << l << '\n';
        int c1 = v1[0], c2 = v2[0];
        int i1 = 0, i2 = 0;

        for (int i = 0; i < l; i++)
        {
            if (c1 > v1[i])
                c1 = v1[i], i1 = i;
            if (c2 > v2[i])
                c2 = v2[i], i2 = i;
        }

        for (int i = 0; i < m; i++)
            value[i] = (types[i] == 1 ? 1ll * costs[i] * c1 : 1ll * costs[i] * c2);
        
        nth_element(value.begin(), value.begin() + k - 1, value.end());
        int cnt = k;
        for (int i = 0; i < m; i++)
        {
            if ((types[i] == 1 ? 1ll * costs[i] * c1 : 1ll * costs[i] * c2) < value[k-1])
                cout << i + 1 << ' ' << (types[i] == 1 ?  i1 + 1 : i2 + 1) << '\n', cnt --;
        }
        for (int i = 0; i < m; i++)
        {
            if ((types[i] == 1 ? 1ll * costs[i] * c1 : 1ll * costs[i] * c2) == value[k-1] && cnt)
                cout << i + 1 << ' ' << (types[i] == 1 ?  i1 + 1 : i2 + 1) << '\n', cnt --;
        }
    }
    else
        cout << -1 << '\n';

    return 0;
}