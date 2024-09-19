#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, s, ans = 0;
    cin >> n >> s;
    vector<int> cnt(n), in(n), out(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i != s - 1)
            cnt[x]++;
        if (i == s - 1 && x)
            ans++;
        if (i != s - 1 && !x)
            out[n - 1]++;
    }
    for (int i = 1; i < n; i++)
    {
        in[i] = in[i - 1];
        if (!cnt[i])
        {
            in[i]++;
        }
    }
    for (int i = n - 2; i >= 1; i--)
    {
    	
        out[i] = out[i + 1]+cnt[i+1];
    }
    int res = 1e9;
    for (int i = 1; i < n; i++)
    {
        res = min(res, max(in[i], out[i]));
    }
    if(n==1)res=0;
    cout << ans + res << endl;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    //	cin>>t;
    while (t--)
    {
        solve();
    }
}
