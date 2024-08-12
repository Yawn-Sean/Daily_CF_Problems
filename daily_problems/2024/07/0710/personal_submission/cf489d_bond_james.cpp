/*
    ੴ ਸਤਿ ਨਾਮੁ ਕਰਤਾ ਪੁਰਖੁ ਨਿਰਭਉ ਨਿਰਵੈਰੁ ਅਕਾਲ ਮੂਰਤਿ ਅਜੂਨੀ ਸੈਭੰ ਗੁਰ ਪ੍ਰਸਾਦਿ
*/
#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define int long long
using namespace std;
using ll = long long;
using lld = long double;
#define mod 10000000007
#define INF 1e18
#define pi 3.141592653589793238462
#define pb push_back
#define ppb pop_back
#define mp make_pair

void solve()
{
    int n, s;
    cin >> n >> s;

    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < s; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }

    vector<int> cnt(n + 1, 0);
    long long ans = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j : edges[i])
        {
            for (int k : edges[j])
            {
                cnt[k]++;
            }
        }

        for (int p = 0; p <= n; p++)
        {
            if (p != i)
            {
                ans += (long long)cnt[p] * (cnt[p] - 1) / 2;
            }
            cnt[p] = 0;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}