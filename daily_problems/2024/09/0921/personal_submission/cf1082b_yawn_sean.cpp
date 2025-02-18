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

    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0, l = 0, r = 0, cnt = 0, cnt_g = 0;

    while (l < n) {
        if (s[l] == 'G') cnt_g ++;

        while (r < n && cnt + (s[r] == 'S') <= 1)
            cnt += (s[r ++] == 'S');
        
        ans = max(ans, r - l);
        cnt -= (s[l ++] == 'S');
    }

    cout << min(ans, cnt_g);

    return 0;
}