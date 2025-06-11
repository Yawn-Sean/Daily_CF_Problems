#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void sol()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    map<int, int> mp;
    for (int i = 0; i < n; ++i) mp[a[i]] = i; // 记录原始位置

    sort(a.begin(), a.end());
    int now = 1;
    vector<int> ans(n);
    vector<int> vis(n, 0);
    
    for (int i = 0; i < n; ++i)
    {
        if (vis[i]) continue;
        vis[i] = 1;
        int lst = a[i];
        ans[mp[a[i]]] = now;

        int pos = i;
        while (true)
        {
            auto it = lower_bound(a.begin() + pos + 1, a.end(), lst + d + 1);
            if (it == a.end()) break;

            int j = it - a.begin();
            if (vis[j]) { pos = j; continue; }
            vis[j] = 1;
            lst = a[j];
            ans[mp[a[j]]] = now;
            pos = j;
        }
        now++;
    }

    cout << now - 1 << endl;
    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    sol();
    return 0;
}
