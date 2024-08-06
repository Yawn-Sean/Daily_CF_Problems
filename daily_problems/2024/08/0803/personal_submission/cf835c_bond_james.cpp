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
const int MAX_N = 105;
const int MAX_C = 11;
int brightness[MAX_C][MAX_N][MAX_N] = {0};
void solve()
{
    int n, q, c;
    cin >> n >> q >> c;
    
    vector<array<int, 3>> stars(n);
    for (int i = 0; i < n; ++i) {
        int x, y, s;
        cin >> x >> y >> s;
        stars[i] = {x, y, s};
        for (int t = 0; t <= c; ++t) {
            brightness[t][x][y] += (s + t) % (c + 1);
        }
    }
    
    for (int t = 0; t <= c; ++t) {
        for (int x = 1; x < MAX_N; ++x) {
            for (int y = 1; y < MAX_N; ++y) {
                brightness[t][x][y] += brightness[t][x-1][y] + brightness[t][x][y-1] - brightness[t][x-1][y-1];
            }
        }
    }
    
    for (int i = 0; i < q; ++i) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int mod_t = t % (c + 1);
        int result = brightness[mod_t][x2][y2] - brightness[mod_t][x1-1][y2] - brightness[mod_t][x2][y1-1] + brightness[mod_t][x1-1][y1-1];
        cout << result << "\n";
    }
}

int32_t main()
{
    FAST_IO;
    int tc = 1;
    // cin>>tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}