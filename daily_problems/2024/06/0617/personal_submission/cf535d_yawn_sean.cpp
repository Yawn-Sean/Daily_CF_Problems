#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    int len = s.size();

    vector<int> pos(m);
    for (int i = 0; i < m; i ++)
        cin >> pos[i], pos[i] --;
    
    vector<int> z(len);

    int j = 0;
    for (int i = 1; i < len; i ++) {
        z[i] = (j + z[j] <= i ? 0 : min(j + z[j] - i, z[i-j]));
        while ((i + z[i] < len) && (s[z[i]] == s[i+z[i]])) z[i] ++;
        if (j + z[j] < i + z[i]) j = i; 
    }

    for (int i = 1; i < m; i ++) {
        int idx = pos[i] - pos[i-1]; 
        if (idx >= len) continue;
        if (z[idx] + idx != len) {
            cout << "0\n";
            return 0;
        }
    }

    vector<int> diff(n + 1);
    for (auto &p: pos)
        diff[p] ++, diff[p+len] --;

    long long ans = 1;
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i ++) {
        diff[i+1] += diff[i];
        if (!diff[i]) ans = ans * 26 % mod;
    }
    cout << ans << '\n';

    return 0;
}