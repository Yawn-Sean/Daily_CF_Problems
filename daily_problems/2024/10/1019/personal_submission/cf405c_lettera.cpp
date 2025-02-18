#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<vector<int>> a(n + 1,vector<int>(n+1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++){
    		ans=(ans+a[i][j]*a[j][i])%2;
    	}
    }
    int q;
    cin>>q;
    while(q--)
    {
    	int op,x;
    	cin>>op;
    	if(op==3)
    	{
    		cout<<ans;
    	}
    	else
    	{
    		cin>>x;
    		ans^=1;
    	}
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
