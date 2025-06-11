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

    int n, m;
    string s;
    cin >> n >> s >> m;

    vector<int> check_a(n + 1), check_b(n + 1), cnt_q(n + 1);

    for (int i = 0; i < n; i ++) 
        cnt_q[i + 1] = cnt_q[i] + (s[i] == '?');
    
    for (int i = n - 1; i >= 0; i --) {
        check_a[i] = (s[i] != 'b' ? check_b[i + 1] + 1 : 0);
        check_b[i] = (s[i] != 'a' ? check_a[i + 1] + 1 : 0);
    }

    vector<int> dp(n + 1, 0), change(n + 1, 0);

    for (int i = 0; i < n; i ++) {
        if (dp[i] > dp[i + 1] || (dp[i] == dp[i + 1] && change[i] < change[i + 1])) {
            dp[i + 1] = dp[i];
            change[i + 1] = change[i];
        }

        if (check_a[i] >= m) {
            int nv = dp[i] + 1, nc = change[i] + cnt_q[i + m] - cnt_q[i];

            if (nv > dp[i + m] || (nv == dp[i + m] && nc < change[i + m])) {
                dp[i + m] = nv;
                change[i + m] = nc;
            }
        }
    }

    cout << change[n];

    return 0;
}